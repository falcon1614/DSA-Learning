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
    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    // Print Sorted Values
    cout << "Sorted Elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
