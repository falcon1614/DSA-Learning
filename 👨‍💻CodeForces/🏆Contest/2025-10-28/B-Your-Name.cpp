#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;


    sort(s.begin(), s.end());
    sort(t.begin(), t.end());


    if (s == t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        solve();
    }

    return 0;
}
