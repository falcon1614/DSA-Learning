// https://cses.fi/problemset/task/1091

#include<bits/stdc++.h>
using namespace std;

int main(){
  int  n,m;
  cin>>n>>m;
  // price of each ticket.
  vector<int>h;
  for(int i=0; i<n; i++){
    cin>>h[i];
  }
  // maximum price
  vector<int>t;
  for(int i=0; i<m; i++){
    cin>>t[i];
  }

  sort(h.begin(),h.end());

  int start = 0;
  int end = n-1;
  int i = 0;
  int ans;
  while(start<=end){
    int mid = start+(end-start)/2;
    if(h[mid]==t[i]){
      ans = h[mid];
      i++;
      h[mid].pop();
    }
    else if(h[mid]<t[i]){
      start = mid+1;
      ans = max(h[mid],ans);
    }else{
      end = mid-1;
    }
    cout<<ans;
  }
  return 0;
}
