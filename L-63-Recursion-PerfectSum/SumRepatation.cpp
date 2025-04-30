#include<iostream>
using namespace std;
int Repatation(int arr[], int index, int n, int sum){
  // Base Case
  if(sum==0) return 1;
  if(index==n || sum < 0) return 0;

  return Repatation(arr,index+1,n,sum)+Repatation(arr,index,n,sum-arr[index]);
}
int main(){
  int arr[] = {2,3,4};
  int sum = 6;
  cout << Repatation(arr,0,3,sum)<<" ";
  cout<<endl;
  return 0;
}
