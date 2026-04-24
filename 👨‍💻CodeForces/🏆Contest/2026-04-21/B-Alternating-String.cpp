#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int bad = 0;

    for (int i = 0; i + 1 < s.size(); i++) {
        if (s[i] == s[i + 1]) bad++;
    }

    cout << (bad <= 2 ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
