#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++){
      cin >> a[i];
    }

    long long count = 0;
    for (int i = 0; i < (int)a.size() - 1; i++) {
        for (int j = i + 1; j < (int)a.size(); j++) {
            if (a[i] > a[j]) {
                count++;
                a.erase(a.begin() + j);
                j--;
            }
        }
    }
    cout << count << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}
// Learn from this question how to delete elements from a vector while iterating over it.
