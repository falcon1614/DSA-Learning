#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');

    string period;

    if (h == 0) {
        h = 12;
        period = "AM";
    } 
    else if (h < 12) {
        period = "AM";
    } 
    else if (h == 12) {
        period = "PM";
    } 
    else {
        h -= 12;
        period = "PM";
    }

    if (h < 10) cout << 0;
    cout << h << ":";
    
    if (m < 10) cout << 0;
    cout << m << " " << period << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
