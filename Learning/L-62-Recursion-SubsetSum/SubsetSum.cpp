#include<iostream>
#include<vector>
using namespace std;
void SubsetSum(int arr[],int index, int n, int sum){
  // Base Case
  if(index==n){
    cout << sum <<" ";
    return;
  }
  // No Include
  SubsetSum(arr,index+1,n,sum);
  // INclude
  SubsetSum(arr,index+1,n,sum+arr[index]);
}
int main(){
  int arr[] = {1,2,3};
  SubsetSum(arr,0,3,0);
  return 0;
}
