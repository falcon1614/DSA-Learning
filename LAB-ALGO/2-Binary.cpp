#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr = {2,5,8,12,16,23,38,56,72,91};

    int target = 23;
    int left = 0, right = arr.size() - 1;

    // Binary Search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            cout << "Element found at index: " << mid << endl;
            return 0;
        }
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << "Element not found" << endl;
    return 0;
}
