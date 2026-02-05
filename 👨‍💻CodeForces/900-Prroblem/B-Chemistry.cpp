#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n, k;
  cin>> n >> k;
  string s;
  cin>>s;

  unordered_map<char,int> mp;
  for(auto it:s){
    mp[it]++;
  }

  int count = 0;
  for(auto it: mp){
    if(it.second % 2 == 1){
      count++;
    }
  }

  if(count-1 > k){
    cout<<"NO \n";
  }
  else{
    cout<<"YES \n";
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
