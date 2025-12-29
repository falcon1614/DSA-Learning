#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (s.find("2026") != string::npos) {
        cout << 0 << "\n";
        return;
    }

    if (s.find("2025") == string::npos) {
        cout << 0 << "\n";
        return;
    }

    // "2025" present and "2026" absent
    cout << 1 << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
