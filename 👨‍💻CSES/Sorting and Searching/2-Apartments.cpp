#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    list<int> ln;
    list<int> lm;

    // Input for list ln
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ln.push_back(x);
    }

    // Input for list lm
    for(int i = 0; i < m; i++) {
        int y;
        cin >> y;
        lm.push_back(y);
    }

    int count = 0;

    for (auto it = ln.begin(); it != ln.end(); it++) {
        int target1 = *it - k;
        int target2 = *it + k;

        // Use std::find from algorithm to search in ln
        if (find(lm.begin(), lm.end(), target1) != lm.end() || find(lm.begin(), lm.end(), target2) != lm.end()) {
            count++;
            lm.pop()
        }
    }

    cout << count << endl;
    return 0;
}
