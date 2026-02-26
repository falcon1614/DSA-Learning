#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (n % 2 == 0 || k % 2 == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
