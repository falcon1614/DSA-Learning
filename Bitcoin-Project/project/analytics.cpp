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

// ============== Utility ===================
static bool isNaN(double x) { return std::isnan(x); }

// ============== Data Model =================
class CryptoRecord {
public:
    // CSV fields
    string timeOpen, timeClose, timeHigh, timeLow, name, timestamp;
    double open = 0.0, high = 0.0, low = 0.0, close = 0.0;
    double volume = 0.0, marketCap = 0.0, circulatingSupply = 0.0;

    // Indicators + prediction
    double sma5, sma10, rsi14, vol10, predictedClose;

    CryptoRecord() {
        double nan = numeric_limits<double>::quiet_NaN();
        sma5 = sma10 = rsi14 = vol10 = predictedClose = nan;
    }

    void load(const vector<string>& t) {
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
};

// ============== CSV Loader =================
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
        while (getline(ss, token, delim))
            tokens.push_back(token);
        return tokens;
    }

    static void removeQuotes(string& s) {
        if (!s.empty() && s.front() == '"') s.erase(0, 1);
        if (!s.empty() && s.back() == '"') s.pop_back();
    }
};

// ========== Indicator Calculator ============
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
            for (size_t j = i + 1 - window; j <= i; ++j)
                sum += recs[j].close;
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
            for (size_t j = i + 1 - window; j <= i; ++j)
                sum += recs[j].close;
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

// ========== Linear Regression Model =========
class LinearRegressionModel {
public:
    // features: open, high, low, volume
    vector<double> weights;      // w0 (bias) + 4 features
    vector<double> featureMean;  // 4
    vector<double> featureStd;   // 4
    double learningRate;
    int epochs;

    LinearRegressionModel(double lr = 0.01, int ep = 1000)
        : learningRate(lr), epochs(ep) {}

    void fit(const vector<CryptoRecord>& recs) {
        if (recs.empty()) return;

        const int featCount = 4;
        size_t n = recs.size();

        featureMean.assign(featCount, 0.0);
        featureStd.assign(featCount, 0.0);
        weights.assign(featCount + 1, 0.0); // bias + features

        // mean
        for (const auto& r : recs) {
            featureMean[0] += r.open;
            featureMean[1] += r.high;
            featureMean[2] += r.low;
            featureMean[3] += r.volume;
        }
        for (int j = 0; j < featCount; ++j)
            featureMean[j] /= n;

        // std
        for (const auto& r : recs) {
            featureStd[0] += pow(r.open   - featureMean[0], 2);
            featureStd[1] += pow(r.high   - featureMean[1], 2);
            featureStd[2] += pow(r.low    - featureMean[2], 2);
            featureStd[3] += pow(r.volume - featureMean[3], 2);
        }
        for (int j = 0; j < featCount; ++j) {
            featureStd[j] = sqrt(featureStd[j] / n);
            if (featureStd[j] == 0.0) featureStd[j] = 1.0;
        }

        // gradient descent
        for (int epoch = 0; epoch < epochs; ++epoch) {
            vector<double> grad(featCount + 1, 0.0);

            for (const auto& r : recs) {
                vector<double> x = makeFeatures(r);
                double y = r.close;

                double y_pred = 0.0;
                for (size_t j = 0; j < weights.size(); ++j)
                    y_pred += weights[j] * x[j];

                double error = y_pred - y;
                for (size_t j = 0; j < grad.size(); ++j)
                    grad[j] += error * x[j];
            }

            for (size_t j = 0; j < weights.size(); ++j)
                weights[j] -= learningRate * grad[j] / n;
        }

        double loss = 0.0;
        for (const auto& r : recs) {
            double pred = predict(r);
            double diff = pred - r.close;
            loss += diff * diff;
        }
        loss /= n;
        cout << "Training completed. MSE = " << loss << "\n";
    }

    double predict(const CryptoRecord& r) const {
        if (weights.empty()) return r.close;
        vector<double> x = makeFeatures(r);
        double y_pred = 0.0;
        for (size_t j = 0; j < weights.size(); ++j)
            y_pred += weights[j] * x[j];
        return y_pred;
    }

private:
    vector<double> makeFeatures(const CryptoRecord& r) const {
        vector<double> x(5, 1.0);
        x[1] = (r.open   - featureMean[0]) / featureStd[0];
        x[2] = (r.high   - featureMean[1]) / featureStd[1];
        x[3] = (r.low    - featureMean[2]) / featureStd[2];
        x[4] = (r.volume - featureMean[3]) / featureStd[3];
        return x;
    }
};

// ============== JSON Writer =================
class JSONWriter {
public:
    static void write(const string& filename, const vector<CryptoRecord>& recs) {
        ofstream out(filename);
        if (!out.is_open()) {
            cerr << "Error opening JSON file: " << filename << "\n";
            return;
        }

        out << fixed << setprecision(6);
        out << "[\n";
        for (size_t i = 0; i < recs.size(); ++i) {
            const auto& r = recs[i];
            out << "  {\n";
            out << "    \"timestamp\": \"" << r.timestamp << "\",\n";
            out << "    \"close\": " << r.close << ",\n";
            out << "    \"predictedClose\": " << (isNaN(r.predictedClose) ? r.close : r.predictedClose) << ",\n";
            out << "    \"sma5\": " << (isNaN(r.sma5) ? r.close : r.sma5) << ",\n";
            out << "    \"sma10\": " << (isNaN(r.sma10) ? r.close : r.sma10) << ",\n";
            out << "    \"rsi14\": " << (isNaN(r.rsi14) ? 50.0 : r.rsi14) << ",\n";
            out << "    \"volatility10\": " << (isNaN(r.vol10) ? 0.0 : r.vol10) << "\n";
            out << "  }";
            if (i + 1 < recs.size()) out << ",";
            out << "\n";
        }
        out << "]\n";

        cout << "JSON written to: " << filename << "\n";
    }
};

// ===================== main =====================
int main() {
    // 1. Load CSV
    CSVLoader loader;
    vector<CryptoRecord> records = loader.loadFile("../data/data.csv");
    if (records.empty()) {
        cout << "No records loaded. Check data.csv\n";
        return 0;
    }
    cout << "Loaded " << records.size() << " records.\n";

    // 2. Compute indicators
    IndicatorCalculator::computeAll(records);

    // 3. Train regression model (on all rows for now)
    LinearRegressionModel model(0.01, 1500);
    model.fit(records);

    // 4. Predict for each row
    for (auto& r : records) {
        r.predictedClose = model.predict(r);
    }

    // 5. Export as JSON for website
    JSONWriter::write("output.json", records);

    return 0;
}
