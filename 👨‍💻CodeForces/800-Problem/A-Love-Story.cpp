#include<bits/stdc++.h>
using namespace std;
void solve(){
  string s;
  cin>>s;

  string g = "codeforces";
  int count = 0;
  for(int i=0; i<g.size(); i++){
    if(s[i]!=g[i]){
      count++;
    }
  }
  cout<<count<<"\n";
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
