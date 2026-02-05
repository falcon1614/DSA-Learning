#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int mx = a[i];
        int pos = -1;

        for (int j = i + 1; j < n; j++) {
            if (a[j] > mx) {
                mx = a[j];
                pos = j;
            }
        }

        if (pos != -1) {
            reverse(a.begin() + i, a.begin() + pos + 1);
            break;
        }
    }

    for (int x : a) {
        cout << x << " ";
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
