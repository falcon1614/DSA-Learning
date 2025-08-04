// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;

// Function to find the kth smallest element
int kthSmallest(vector<int> &arr, int k) {
    // Max heap to store k smallest elements
    priority_queue<int> p;

    // Insert first k elements into the heap
    for (int i = 0; i < k; i++) {
        p.push(arr[i]);
    }

    // Process remaining elements
    for (int i = k; i < arr.size(); i++) {
        if (arr[i] < p.top()) {
            p.pop();
            p.push(arr[i]);
        }
    }

    // The top of the heap is the kth smallest element
    return p.top();
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Invalid k. It must be between 1 and " << n << endl;
        return 1;
    }

    int result = kthSmallest(arr, k);
    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}

