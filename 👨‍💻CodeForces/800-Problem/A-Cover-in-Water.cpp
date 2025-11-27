#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count_dot = 0;
    bool has_three = false;

    for (int i = 0; i < n; i++) {
        if (s[i] == '.') count_dot++;

        if (i + 2 < n) {
            if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') {
                has_three = true;
            }
        }
    }

    if (has_three) {
        cout << 2 << endl;
    } else {
        cout << count_dot << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
