#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        long long temp;
        cin >> temp;
        a[i] = a[i - 1] + temp;
    }

    long long totalSum = a[n];

    while (q--) {
        long long l, r, k;
        cin >> l >> r >> k;

        long long oldSum = a[r] - a[l - 1];
        long long newSum = 1LL * (r - l + 1) * k;

        long long ans = totalSum - oldSum + newSum;

        if (ans % 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
