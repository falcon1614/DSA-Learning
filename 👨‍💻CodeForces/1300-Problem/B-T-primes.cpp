#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 1;
vector<bool> sieve(MX, true);

void precompute() {
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i < MX; i++) {
        if (sieve[i]) {
            for (int j = i * i; j < MX; j += i) {
                sieve[j] = false;
            }
        }
    }
}

void solve() {
    long long n;
    cin >> n;

    long long sq = sqrt(n);

    if (sq * sq == n && sieve[sq]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
