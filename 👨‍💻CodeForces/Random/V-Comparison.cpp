#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    char s;
    cin >> a >> s >> b;

    bool ok = false;

    if (s == '<') {
        ok = (a < b);
    } else if (s == '>') {
        ok = (a > b);
    } else if (s == '=') {
        ok = (a == b);
    }

    if (ok)
        cout << "Right\n";
    else
        cout << "Wrong\n";

    return 0;
}
