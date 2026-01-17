#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int currentZeros = 0;
    int maxZeros = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            currentZeros++;
            maxZeros = max(maxZeros, currentZeros);
        } else {
            currentZeros = 0;
        }
    }

    cout << maxZeros << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
