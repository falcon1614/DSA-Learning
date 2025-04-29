#include<iostream>
#include<string>
#include<vector>
using namespace std;
void subseq(string str, int index, int n, vector<string>&ans, string&temp){
  // Base Value
  if(index==n){
    ans.push_back(temp);
    return;
  }
  // Not Include
  subseq(str,index+1,n,ans,temp);
  // INclude
  temp.push_back(str[index]);
  subseq(str,index+1,n,ans,temp);
  temp.pop_back();
}
int main(){
  string str = "abcd";
  vector<string> ans;
  string temp;
  subseq(str,0,str.size(),ans,temp);
  // Print Value
  for(int i=0; i<ans.size(); i++){
    cout << ans[i]<<" ";
  }
  return 0;
}
