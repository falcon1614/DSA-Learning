#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    long long rem = a % b;
    if (rem == 0) {
        cout << 0 << "\n";
    } else {
        cout << b - rem << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
