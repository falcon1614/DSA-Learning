#include <bits/stdc++.h>
using namespace std;

void Beautiful_Average(vector<int> &arr) {
    int max_avg = *max_element(arr.begin(), arr.end());
    cout << max_avg << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Beautiful_Average(arr);
    }
    return 0;
}
