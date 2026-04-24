#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long x, y;
    cin >> x >> y;

    if (y == 2 * x)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
