#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int sleep = 0;
    int blocked = 0;

    for (int i = 0; i < n; i++) {

        if (s[i] == '1') {

            blocked = k;
        }
        else {
            if (blocked == 0) {
                sleep++;
            } else {
                blocked--;
            }
        }
    }

    cout << sleep << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
