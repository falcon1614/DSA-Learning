#include<iostream>
#include<vector>
using namespace std;
bool targetsum(int arr[], int index,int n, int target){
  if(target==0) return 1;
  if(index==1||target<0) return 0;

  return targetsum(arr,index+1,n,target)||targetsum(arr,index+1,n,target-arr[index]);
}
int main(){
  int arr[] = {1,4,6,3,6};
  int target = 13;
  cout << targetsum(arr,0,5,target)<<" ";
  cout<<endl;
  return 0;
}
