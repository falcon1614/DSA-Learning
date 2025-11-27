#include<iostream>
using namespace std;
bool binary(int arr[], int start, int end, int key){
    if(start > end){
        return 0;
    }
    int mid = start + (end-start)/2;
    if(arr[mid] == key){
        cout<<"Element at Index IS: "<<mid<<endl;
        return 1;
    }else if(arr[mid] < key){
        return binary(arr,mid+1,end,key);
    }else{
        return binary(arr,start,mid-1,key);
    }
}
int main(){
    int arr[] = {3,8,11,15,20,22};
    int n = sizeof(arr)/sizeof(arr[0]);
    int start = 0;
    int end = 7;
    int key = 20;
    cout << binary(arr,start,end,key);
    return 0;
}
