#include<iostream>
#include<vector>
using namespace std;
void subsequence(int arr[],int index,int n,vector<vector<int>>&ans,vector<int>&temp){
  //  Base Condition
  if(index==n){
    ans.push_back(temp);
    return;
  }
  // Not Include
  subsequence(arr,index+1,n,ans,temp);
  // Include
  temp.push_back(arr[index]);
  subsequence(arr,index+1,n,ans,temp);
  // Space Optimize
  temp.pop_back();
}
using namespace std;
int main(){
  int arr[] = {1,2,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  vector<vector<int>>ans;
  vector<int>temp;
  subsequence(arr,0,n,ans,temp);
  // Print Value
  for(int i=0; i<ans.size(); i++){
    for(int j=0; j<ans[i].size(); j++){
      cout<< ans[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
