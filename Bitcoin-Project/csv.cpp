#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// -------------------------------------------------------------
// Class to represent each OHLCV record
// -------------------------------------------------------------
class CryptoRecord {
public:
    string timeOpen, timeClose, timeHigh, timeLow, name, timestamp;
    double open, high, low, close, volume, marketCap, circulatingSupply;

    // Load values from parsed tokens
    void load(const vector<string>& t) {
        timeOpen = t[0];
        timeClose = t[1];
        timeHigh = t[2];
        timeLow = t[3];
        name = t[4];

        open = stod(t[5]);
        high = stod(t[6]);
        low = stod(t[7]);
        close = stod(t[8]);
        volume = stod(t[9]);
        marketCap = stod(t[10]);
        circulatingSupply = stod(t[11]);

        timestamp = t[12];
    }

    void print() {
        cout << "Name: " << name << "\nOpen: " << open
             << " High: " << high << " Low: " << low
             << " Close: " << close << "\n";
    }
};

// -------------------------------------------------------------
// Simple Machine Learning Predictor
// y = a1*open + a2*high + a3*low + b
// -------------------------------------------------------------
class PricePredictor {
public:
    // Example weights (normally learned from data)
    double w1 = 0.25;
    double w2 = 0.30;
    double w3 = 0.20;
    double bias = 0.10;

    double predict(const CryptoRecord& rec) {
        // Very simple ML model
        return w1 * rec.open + w2 * rec.high + w3 * rec.low + bias;
    }
};

// -------------------------------------------------------------
// CSV Loader Class
// -------------------------------------------------------------
class CSVLoader {
public:
    vector<CryptoRecord> loadFile(const string& filename) {
        ifstream file(filename);
        vector<CryptoRecord> data;
        string line;

        if (!file.is_open()) {
            cerr << "Error opening file.\n";
            return data;
        }

        getline(file, line); // skip header

        while (getline(file, line)) {
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
    // Split CSV by semicolon
    vector<string> split(const string& s, char delim) {
        vector<string> tokens;
        string token;
        stringstream ss(s);

        while (getline(ss, token, delim)) tokens.push_back(token);
        return tokens;
    }

    // Remove double quotes from tokens
    static void removeQuotes(string& s) {
        if (!s.empty() && s.front() == '"') s.erase(0, 1);
        if (!s.empty() && s.back() == '"') s.pop_back();
    }
};

// -------------------------------------------------------------
// Main Program
// -------------------------------------------------------------
int main() {
    CSVLoader loader;
    PricePredictor predictor;

    vector<CryptoRecord> records = loader.loadFile("Bitcoin.csv");

    if (records.empty()) {
        cout << "No records loaded.\n";
        return 0;
    }

    for (auto& rec : records) {
        rec.print();
        double predicted = predictor.predict(rec);
        cout << "Predicted Next Close Price: " << predicted << "\n\n";
    }

    return 0;
}
