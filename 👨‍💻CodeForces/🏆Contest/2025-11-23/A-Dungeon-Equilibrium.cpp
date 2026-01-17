#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Count frequency of each number
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    int ans = 0;

    // Check each distinct number
    for (auto it : freq) {
        int x = it.first;     // the number
        int f = it.second;    // how many times it appears

        if (x == 0) {
            // 0 can never be valid, remove all
            ans += f;
        }
        else if (f == x) {
            // already perfect, keep as is
            continue;
        }
        else if (f > x) {
            // either keep x or delete all f
            int remove_to_make_x = f - x;
            int remove_all = f;
            ans += min(remove_to_make_x, remove_all);
        }
        else {
            // f < x, impossible to reach x occurrences, delete all
            ans += f;
        }
    }

    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
