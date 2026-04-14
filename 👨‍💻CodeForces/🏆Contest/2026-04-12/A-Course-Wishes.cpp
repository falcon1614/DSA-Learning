#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> extra(k);
    for (int i = 0; i < k; i++) {
        cin >> extra[i];
    }

    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.rbegin(), v.rend());

    vector<int> ops;

    for (int i = 0; i < n; i++) {
        int value = v[i].first;

        int times = max(0, k + 1 - value);

        for (int j = 0; j < times; j++) {
            ops.push_back(v[i].second);
        }
    }

    cout << ops.size() << "\n";
    for (auto &it : ops) {
        cout << it + 1 << " ";
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
