#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> ans;

    if (x != 1) {
        // Use 1
        for (int i = 0; i < n; i++) {
            ans.push_back(1);
        }
    } else {
        // x == 1, cannot use 1
        if (n % 2 == 0 && k >= 2) {
            // Use 2
            for (int i = 0; i < n / 2; i++) {
                ans.push_back(2);
            }
        } else if (n % 2 == 1 && k >= 3) {
            // Use one 3, rest 2
            ans.push_back(3);
            n -= 3;
            for (int i = 0; i < n / 2; i++) {
                ans.push_back(2);
            }
        } else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    for (int v : ans) {
        cout << v << " ";
    }
    cout << "\n";
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
