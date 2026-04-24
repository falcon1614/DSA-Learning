#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(n == 1) {
        cout << 0 << "\n";
        return;
    }

    int ans = INT_MIN;

    // Case 1: make some element last
    for(int i = 1; i < n; i++) {
        ans = max(ans, a[i] - a[0]);
    }

    // Case 2: make some element first
    for(int i = 1; i < n; i++) {
        ans = max(ans, a[n-1] - a[i]);
    }

    // Case 3: internal rotations
    for(int i = 0; i < n - 1; i++) {
        ans = max(ans, a[i] - a[i+1]);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
