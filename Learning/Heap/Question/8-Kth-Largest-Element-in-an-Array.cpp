// https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/1718203758/

#include <bits/stdc++.h>
using namespace std;

// Function to find the kth largest element
int findKthLargest(vector<int>& nums, int k) {
    // Min Heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> p;

    // Push first k elements into the min heap
    for (int i = 0; i < k; i++) {
        p.push(nums[i]);
    }

    // For the rest of the elements
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] > p.top()) {
            p.pop();
            p.push(nums[i]);
        }
    }

    // Top of the min heap is the k-th largest element
    return p.top();
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Invalid value of k. Must be between 1 and " << n << endl;
        return 1;
    }

    int result = findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}
