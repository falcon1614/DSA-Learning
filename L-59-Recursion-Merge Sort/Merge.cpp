#include<iostream>
#include<vector>
using namespace std;
// Merge two sorted subarrays
void merge(int arr[], int start, int mid, int end){
    // Create Space For Store After Sort Data
    vector<int> temp(end-start+1);
    int left = start;
    int right = mid+1;
    int index = 0;
    // Merging two sorted halves
         while (left <= mid && right <= end){
             if(arr[left] <= arr[right]){
                 temp[index] = arr[left];
                 index++;
                 left++;
             } else {
                 temp[index] = arr[right];
                 right++;
                 index++;
             }
         }
 // Left Side Data Are Available || Copy remaining left-side elements
    while(left <= mid){
        temp[index] = arr[left];
         index++;
         left++;
    }
    // Right Side Data Are Available || Copy remaining right-side elements
    while (right <= end){
        temp[index] = arr[right];
        index++;
        right++;
    }
    // Put All Temp Value in Arr || Copy sorted values back to the original array
    index = 0;
    while (start<=end){
        arr[start] = temp[index];
        start++;
        index++;
    }
}
void mergeSort(int arr[], int start, int end){
    int mid = start+(end-start)/2;
    // Base Condition
    if(start==end){
        return;
    }
    // Left Side Of Array
    mergeSort(arr,start,mid);
    // Right Side Of Array
    mergeSort(arr,mid+1,end);
    // Merge All left and Right Element
    merge(arr,start,mid,end);
}
int main(){
    int arr[] = {2,1,4,6,7,8,9,3,7}; // 9 elements
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    // Print the sorted array
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// Time Complexity : O(n log n)
// Space Complexity : (n + log n)
