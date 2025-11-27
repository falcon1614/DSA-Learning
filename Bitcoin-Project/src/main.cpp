#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>
#include <algorithm>

using namespace std;

// ======================= Utility ==========================
static bool isNaN(double x) {
    return std::isnan(x);
}

// =================== Data Model Class ======================
class CryptoRecord {
public:
    // Original CSV fields
    string timeOpen, timeClose, timeHigh, timeLow, name, timestamp;
    double open = 0.0, high = 0.0, low = 0.0, close = 0.0;
    double volume = 0.0, marketCap = 0.0, circulatingSupply = 0.0;

    // Derived indicators
    double sma5, sma10, rsi14, vol10;
    double predictedClose;

    CryptoRecord() {
        double nan = numeric_limits<double>::quiet_NaN();
        sma5 = sma10 = rsi14 = vol10 = predictedClose = nan;
    }

    void load(const vector<string>& t) {
        // Expecting exactly 13 tokens as per CSV
        timeOpen = t[0];
        timeClose = t[1];
        timeHigh = t[2];
        timeLow  = t[3];
        name     = t[4];

        open     = stod(t[5]);
        high     = stod(t[6]);
        low      = stod(t[7]);
        close    = stod(t[8]);
        volume   = stod(t[9]);
        marketCap = stod(t[10]);
        circulatingSupply = stod(t[11]);

        timestamp = t[12];
    }

    void printShort() const {
        cout << "Name: " << name
             << " | Open: " << open
             << " High: " << high
             << " Low: " << low
             << " Close: " << close << "\n";
    }
};

// ======================= CSV Loader =======================
class CSVLoader {
public:
    vector<CryptoRecord> loadFile(const string& filename) {
        ifstream file(filename);
        vector<CryptoRecord> data;
        string line;

        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << "\n";
            return data;
        }

        // Skip header
        if (!getline(file, line)) {
            cerr << "File is empty.\n";
            return data;
        }

        while (getline(file, line)) {
            if (line.empty()) continue;
            vector<string> tokens = split(line, ';');
            for (string &t : tokens) removeQuotes(t);

            if (tokens.size() < 13) continue;

            CryptoRecord rec;
            rec.load(tokens);
            data.push_back(rec);
        }

        return data;
    }

private:
    static vector<string> split(const string& s, char delim) {
        vector<string> tokens;
        string token;
        stringstream ss(s);

        while (getline(ss, token, delim)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    static void removeQuotes(string& s) {
        if (!s.empty() && s.front() == '"') s.erase(0, 1);
        if (!s.empty() && s.back() == '"') s.pop_back();
    }
};

// =================== Indicator Calculator ==================
class IndicatorCalculator {
public:
    static void computeAll(vector<CryptoRecord>& recs) {
        computeSMA(recs, 5);
        computeSMA(recs, 10);
        computeRSI14(recs);
        computeVolatility(recs, 10);
    }

private:
    static void computeSMA(vector<CryptoRecord>& recs, int window) {
        if (recs.size() < (size_t)window) return;

        for (size_t i = 0; i < recs.size(); ++i) {
            if (i + 1 < (size_t)window) {
                setSMA(recs[i], window, numeric_limits<double>::quiet_NaN());
                continue;
            }
            double sum = 0.0;
            for (size_t j = i + 1 - window; j <= i; ++j) {
                sum += recs[j].close;
            }
            double sma = sum / window;
            setSMA(recs[i], window, sma);
        }
    }

    static void setSMA(CryptoRecord& rec, int window, double value) {
        if (window == 5) rec.sma5 = value;
        if (window == 10) rec.sma10 = value;
    }

    static void computeRSI14(vector<CryptoRecord>& recs) {
        const int period = 14;
        if (recs.size() <= (size_t)period) return;

        vector<double> gains(recs.size(), 0.0);
        vector<double> losses(recs.size(), 0.0);

        for (size_t i = 1; i < recs.size(); ++i) {
            double change = recs[i].close - recs[i-1].close;
            if (change > 0) gains[i] = change;
            else losses[i] = -change;
        }

        double avgGain = 0.0, avgLoss = 0.0;
        for (int i = 1; i <= period; ++i) {
            avgGain += gains[i];
            avgLoss += losses[i];
        }
        avgGain /= period;
        avgLoss /= period;

        double rs = (avgLoss == 0.0) ? 0.0 : (avgGain / avgLoss);
        recs[period].rsi14 = (avgLoss == 0.0) ? 100.0 : (100.0 - 100.0 / (1.0 + rs));

        for (size_t i = period + 1; i < recs.size(); ++i) {
            avgGain = (avgGain * (period - 1) + gains[i]) / period;
            avgLoss = (avgLoss * (period - 1) + losses[i]) / period;
            if (avgLoss == 0.0) {
                recs[i].rsi14 = 100.0;
            } else {
                rs = avgGain / avgLoss;
                recs[i].rsi14 = 100.0 - 100.0 / (1.0 + rs);
            }
        }
    }

    static void computeVolatility(vector<CryptoRecord>& recs, int window) {
        if (recs.size() < (size_t)window) return;

        for (size_t i = 0; i < recs.size(); ++i) {
            if (i + 1 < (size_t)window) {
                recs[i].vol10 = numeric_limits<double>::quiet_NaN();
                continue;
            }
            double sum = 0.0;
            for (size_t j = i + 1 - window; j <= i; ++j) {
                sum += recs[j].close;
            }
            double mean = sum / window;

            double var = 0.0;
            for (size_t j = i + 1 - window; j <= i; ++j) {
                double diff = recs[j].close - mean;
                var += diff * diff;
            }
            var /= window;
            recs[i].vol10 = sqrt(var);
        }
    }
};

// ================= Linear Regression Model ==================
class LinearRegressionModel {
public:
    // features: [open, high, low, volume]
    vector<double> weights; // size = features + 1 (bias)
    vector<double> featureMean;
    vector<double> featureStd;
    double learningRate;
    int epochs;

    LinearRegressionModel(double lr = 0.01, int ep = 1000)
        : learningRate(lr), epochs(ep) {}

    void fit(const vector<CryptoRecord>& recs) {
        if (recs.empty()) return;

        const int featCount = 4; // open, high, low, volume
        size_t n = recs.size();

        featureMean.assign(featCount, 0.0);
        featureStd.assign(featCount, 0.0);
        weights.assign(featCount + 1, 0.0); // w0 + 4 features

        // ---------- Compute mean ----------
        for (const auto& r : recs) {
            featureMean[0] += r.open;
            featureMean[1] += r.high;
            featureMean[2] += r.low;
            featureMean[3] += r.volume;
        }
        for (int j = 0; j < featCount; ++j) {
            featureMean[j] /= n;
        }

        // ---------- Compute std-dev ----------
        for (const auto& r : recs) {
            featureStd[0] += pow(r.open   - featureMean[0], 2);
            featureStd[1] += pow(r.high   - featureMean[1], 2);
            featureStd[2] += pow(r.low    - featureMean[2], 2);
            featureStd[3] += pow(r.volume - featureMean[3], 2);
        }
        for (int j = 0; j < featCount; ++j) {
            featureStd[j] = sqrt(featureStd[j] / n);
            if (featureStd[j] == 0.0) featureStd[j] = 1.0; // avoid division by zero
        }

        // ---------- Gradient Descent ----------
        for (int epoch = 0; epoch < epochs; ++epoch) {
            vector<double> grad(featCount + 1, 0.0); // grad for bias + features

            for (const auto& r : recs) {
                vector<double> x = makeFeatures(r); // normalized
                double y = r.close;

                double y_pred = 0.0;
                for (size_t j = 0; j < weights.size(); ++j)
                    y_pred += weights[j] * x[j];

                double error = y_pred - y;
                for (size_t j = 0; j < grad.size(); ++j)
                    grad[j] += error * x[j];
            }

            for (size_t j = 0; j < weights.size(); ++j) {
                weights[j] -= learningRate * grad[j] / n;
            }
        }

        // Optional: print final loss
        double loss = 0.0;
        for (const auto& r : recs) {
            double pred = predict(r);
            double diff = pred - r.close;
            loss += diff * diff;
        }
        loss /= n;
        cout << "Training completed. Final MSE: " << loss << "\n";
    }

    double predict(const CryptoRecord& rec) const {
        if (weights.empty()) return rec.close; // fallback
        vector<double> x = makeFeatures(rec);
        double y_pred = 0.0;
        for (size_t j = 0; j < weights.size(); ++j)
            y_pred += weights[j] * x[j];
        return y_pred;
    }

private:
    vector<double> makeFeatures(const CryptoRecord& r) const {
        // x[0] = 1 (bias), rest normalized
        vector<double> x(5, 1.0);
        x[1] = (r.open   - featureMean[0]) / featureStd[0];
        x[2] = (r.high   - featureMean[1]) / featureStd[1];
        x[3] = (r.low    - featureMean[2]) / featureStd[2];
        x[4] = (r.volume - featureMean[3]) / featureStd[3];
        return x;
    }
};

// ======================= CSV Writer =========================
class ResultWriter {
public:
    void write(const string& filename, const vector<CryptoRecord>& recs) {
        ofstream out(filename);
        if (!out.is_open()) {
            cerr << "Error opening output file: " << filename << "\n";
            return;
        }

        out << "timeOpen;timeClose;timeHigh;timeLow;name;"
            << "open;high;low;close;volume;marketCap;circulatingSupply;timestamp;"
            << "SMA5;SMA10;RSI14;Volatility10;PredictedClose\n";

        out << fixed << setprecision(6);

        for (const auto& r : recs) {
            out << '"' << r.timeOpen << '"' << ";"
                << '"' << r.timeClose << '"' << ";"
                << '"' << r.timeHigh << '"' << ";"
                << '"' << r.timeLow << '"' << ";"
                << '"' << r.name << '"' << ";"
                << r.open << ";"
                << r.high << ";"
                << r.low << ";"
                << r.close << ";"
                << r.volume << ";"
                << r.marketCap << ";"
                << r.circulatingSupply << ";"
                << '"' << r.timestamp << '"' << ";";

            writeDoubleField(out, r.sma5); out << ";";
            writeDoubleField(out, r.sma10); out << ";";
            writeDoubleField(out, r.rsi14); out << ";";
            writeDoubleField(out, r.vol10); out << ";";
            writeDoubleField(out, r.predictedClose);
            out << "\n";
        }

        cout << "Results written to: " << filename << "\n";
    }

private:
    static void writeDoubleField(ofstream& out, double v) {
        if (isNaN(v)) out << "";
        else out << v;
    }
};

// ==================== ASCII Graph Plotter ===================
class AsciiGrapher {
public:
    static void plotCloseVsPred(const vector<CryptoRecord>& recs, size_t maxPoints = 30) {
        if (recs.empty()) {
            cout << "No data to plot.\n";
            return;
        }

        size_t n = recs.size();
        size_t start = (n > maxPoints) ? n - maxPoints : 0;

        double minVal = numeric_limits<double>::max();
        double maxVal = numeric_limits<double>::lowest();

        for (size_t i = start; i < n; ++i) {
            double c = recs[i].close;
            double p = recs[i].predictedClose;
            if (!isNaN(c)) minVal = min(minVal, c);
            if (!isNaN(p)) minVal = min(minVal, p);
            if (!isNaN(c)) maxVal = max(maxVal, c);
            if (!isNaN(p)) maxVal = max(maxVal, p);
        }

        if (minVal == maxVal) {
            minVal -= 1.0;
            maxVal += 1.0;
        }

        const int width = 60;
        cout << "\nASCII Graph ( * = Close, + = Predicted, X = both )\n";

        for (size_t i = start; i < n; ++i) {
            double c = recs[i].close;
            double p = recs[i].predictedClose;

            string line(width, ' ');
            int posC = -1, posP = -1;

            if (!isNaN(c)) {
                posC = (int)((c - minVal) / (maxVal - minVal) * (width - 1));
            }
            if (!isNaN(p)) {
                posP = (int)((p - minVal) / (maxVal - minVal) * (width - 1));
            }

            if (posC >= 0 && posC < width) line[posC] = '*';
            if (posP >= 0 && posP < width) {
                if (line[posP] == '*') line[posP] = 'X';
                else line[posP] = '+';
            }

            cout << setw(4) << i << " | " << line << "\n";
        }
    }
};

// ========================== main ============================
int main() {
    // 1. Load CSV
    CSVLoader loader;
    vector<CryptoRecord> records = loader.loadFile("../data/data.csv");

    if (records.empty()) {
        cout << "No records loaded. Check data/data.csv\n";
        return 0;
    }

    cout << "Loaded " << records.size() << " records.\n";

    // 2. Compute Indicators
    IndicatorCalculator::computeAll(records);

    // 3. Train Regression Model
    LinearRegressionModel model(0.01, 1500);
    model.fit(records);

    // 4. Predict for each record
    for (auto& r : records) {
        r.predictedClose = model.predict(r);
    }

    // 5. Write output CSV
    ResultWriter writer;
    writer.write("output.csv", records);

    // 6. Show small preview
    cout << "\nSample (last 3 records):\n";
    for (int i = max(0, (int)records.size() - 3); i < (int)records.size(); ++i) {
        const auto& r = records[i];
        cout << "Row " << i
             << " Close=" << r.close
             << " PredClose=" << r.predictedClose
             << " SMA5=" << r.sma5
             << " RSI14=" << r.rsi14 << "\n";
    }

    // 7. ASCII Graph
    AsciiGrapher::plotCloseVsPred(records, 30);

    return 0;
}
