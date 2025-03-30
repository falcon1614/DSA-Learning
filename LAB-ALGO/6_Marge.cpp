#include <iostream>
#include <vector>
using namespace std;
void Merge(int arr[], int start, int mid, int end) {
    vector<int> temp(end - start + 1);
    int left = start, right = mid + 1, index = 0;
    // Merging the two halves
    while (left <= mid && right <= end) {
        if (arr[left] <= arr[right]) {
            temp[index++] = arr[left++];
        } else {
            temp[index++] = arr[right++];
        }
    }
    while (left <= mid) {
        temp[index++] = arr[left++];
    }
    while (right <= end) {
        temp[index++] = arr[right++];
    }
    for (int i = 0; i < temp.size(); i++) {
        arr[start + i] = temp[i];
    }
}
// Merge Sort function
void MergeSort(int arr[], int start, int end) {
    if (start < end) { // Change condition to allow sorting
        int mid = start + (end - start) / 2;
        MergeSort(arr, start, mid);   // Sort left half
        MergeSort(arr, mid + 1, end); // Sort right half
        Merge(arr, start, mid, end);   // Merge both halves
    }
}
int main() {
    int arr[] = {6, 3, 1, 2, 8, 9, 10, 7, 3, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
