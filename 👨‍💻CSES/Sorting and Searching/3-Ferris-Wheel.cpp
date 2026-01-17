// https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    int start = 0, end = n - 1;
    int gondolas = 0;

    while (start <= end) {
        if (p[start] + p[end] <= x) {
            ++start;
            --end;
        } else {
            --end;
        }
        ++gondolas;
    }

    cout << gondolas << endl;
    return 0;
}
