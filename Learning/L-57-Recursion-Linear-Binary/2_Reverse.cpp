// 2: Write a recursive function to reverse the elements of an array.
#include<iostream>
using namespace std;
void reverse(int arr[], int start, int end){
    if (start > end){
        return;
    }
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    return reverse(arr,start+1,end-1);
}
int main(){
    int arr[] = {3,8,11,15,20,22};
    int n = sizeof(arr)/sizeof(arr[0]);
    int start = 0;
    int end = n;
    reverse(arr,start,end);
    // Print
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
