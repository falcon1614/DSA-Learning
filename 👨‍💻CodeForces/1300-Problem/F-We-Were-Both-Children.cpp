#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> freq(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a <= n)
            freq[a]++;
    }

    vector<int> catchCount(n + 1, 0);
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) continue;

        for (int j = i; j <= n; j += i) {
            catchCount[j] += freq[i];
            ans = max(ans, catchCount[j]);
        }
    }

    cout << ans << "\n";
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
