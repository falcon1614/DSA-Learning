#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Start with first gap: from 0 to a1
    int ans = a[0];

    // Middle gaps
    for(int i = 1; i < n; i++) {
        ans = max(ans, a[i] - a[i - 1]);
    }

    // Last gap counted twice (x to last station)
    ans = max(ans, 2 * (x - a[n - 1]));

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
