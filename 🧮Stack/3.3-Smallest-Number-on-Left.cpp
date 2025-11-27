//https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
#include<bits/stdc++.h>
using namespace std;
vector<int> left(vector<int>&arr,int n){
 stack<int> st;
 vector<int> ans(n, -1);
  for(int i=n-1; i>=0; i--){
    while(!st.empty() && arr[st.top()] > arr[i]){
      ans[st.top()] = arr[i];
      st.pop();
    }
    st.push(i);
  }
  return ans;
}
