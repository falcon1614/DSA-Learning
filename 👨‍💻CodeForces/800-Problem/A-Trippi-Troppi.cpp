#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    getline(cin, s);

    string ans = "";
    stringstream ss(s);
    string word;

    // extract each word safely
    while (ss >> word) {
        ans += word[0];
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    while (t--) {
        solve();
    }

    return 0;
}
