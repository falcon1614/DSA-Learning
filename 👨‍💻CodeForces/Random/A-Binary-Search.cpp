

#include <bits/stdc++.h>
using namespace std;

bool binary_search_custom(vector<int>& arr, int x) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == x) {
            return true;
        }
        else if (arr[mid] > x) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (k--) {
        int temp;
        cin >> temp;
        if (binary_search_custom(arr, temp)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
