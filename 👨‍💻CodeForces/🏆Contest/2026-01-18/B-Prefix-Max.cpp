
#include<bits/stdc++.h>
using namespace std;

long long value(vector<int>& a) {
    long long ans = 0;
    int mx = 0;
    for (int x : a) {
        mx = max(mx, x);
        ans += mx;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }

    long long best = value(a);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(a[i], a[j]);
            best = max(best, value(a));
            swap(a[i], a[j]);
        }
    }

    cout << best << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}

