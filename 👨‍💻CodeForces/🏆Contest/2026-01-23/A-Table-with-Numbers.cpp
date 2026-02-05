#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, h, l;
    cin >> n >> h >> l;

    int x = 0, y = 0, z = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a <= h) x++;
        if (a <= l) y++;
        if (a <= min(h, l)) z++;
    }

    int ans = min((x + y - z) / 2,z + min(x - z, y - z));

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
      solve();
    }
}
