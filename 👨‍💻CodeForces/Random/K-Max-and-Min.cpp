#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long mi = min({a, b, c});
    long long mx = max({a, b, c});

    cout << mi << " " << mx << "\n";
    return 0;
}
