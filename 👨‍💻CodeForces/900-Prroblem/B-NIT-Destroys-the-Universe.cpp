#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int cnt_0 = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) cnt_0++;
    }

    // Case 1: All elements are zero
    if(cnt_0 == n) {
        cout << 0 << "\n";
        return;
    }

    int left = 0, right = n - 1;

    // First non-zero from left
    while(left < n && a[left] == 0) left++;

    // First non-zero from right
    while(right >= 0 && a[right] == 0) right--;

    bool found_zero = false;

    // Check zero between first and last non-zero
    for(int i = left; i <= right; i++) {
        if(a[i] == 0) {
            found_zero = true;
            break;
        }
    }

    // If zero exists inside => 2 else 1
    if(found_zero)
        cout << 2 << "\n";
    else
        cout << 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
