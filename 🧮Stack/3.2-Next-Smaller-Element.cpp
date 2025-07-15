// https://www.naukri.com/code360/problems/next-smaller-element_1112581?leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>
using namespace std;

vector<int> smaller(vector<int>&arr){
  int n = arr.size();
  vector<int>ans(n,-1);
  stack<int> st;
  for(int i=0; i<n; i++){
    while(!st.empty()&&arr[st.top()]>arr[i]){
      ans[st.top()] = arr[i];
      st.pop();
    }
    st.push(i);
  }
  return ans;
}

int main(){

  return 0;
}
