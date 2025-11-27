#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    set<long long> ds;

    for (long long i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        ds.insert(x);
    }

    cout << ds.size() << endl;
    return 0;
}

