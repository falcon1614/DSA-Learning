#include<bits/stdc++.h>
using namespace std;
void solve(){
  char c;
  cin>>c;
  string s = "codeforces";
  int pos = s.find(c);
  if(pos!=-1){
    cout<<"YES"<<"\n";
  }
  else{
    cout<<"NO"<<"\n";
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
