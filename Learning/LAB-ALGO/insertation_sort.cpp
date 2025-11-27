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
    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    // Print Sorted Values
    cout << "Sorted Elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
