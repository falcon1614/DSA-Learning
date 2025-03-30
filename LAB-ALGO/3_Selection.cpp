#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter Size of Vector: ";
    cin >> n;
    vector<int> arr(n);
    // Element Entry
    cout << "Enter Elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    // Print Sorted Values
    cout << "Sorted Elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
