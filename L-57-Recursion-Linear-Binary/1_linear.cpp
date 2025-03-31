#include<iostream>
using namespace std;
bool Linear(int arr[], int index, int x, int n) {
    if(index==n){
        return 0;
    }
    if(arr[index]==x){
        cout <<"Index is : "<<index<<endl;
        return 1;
    }
    return Linear(arr, index+1, x, n);
}
int main(){
    int arr[7] = {2,4,7,3,11,8,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 11;
    int index = 0;
    cout <<Linear(arr,index,x,n);
    return 0;
}
