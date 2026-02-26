#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int ln = s.size();

    if (ln % 2 == 1) {
        cout << "NO\n";
        return;
    }

    int mid = ln / 2;
    for (int i = 0; i < mid; i++) {
        if (s[i] != s[mid + i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
