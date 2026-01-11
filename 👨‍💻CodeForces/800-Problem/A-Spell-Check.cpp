#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n != 5) {
        cout << "NO\n";
        return;
    }

    sort(s.begin(), s.end());
    string target = "Timur";
    sort(target.begin(), target.end());

    if (s == target)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
