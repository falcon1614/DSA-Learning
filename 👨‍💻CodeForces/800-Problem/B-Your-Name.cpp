//
#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;
  string s,t;
  cin>>s>>t;

  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  for(int i=0; i<=n; i++){
    if(s[i] != t[i]){
      cout<<"NO \n";
      return;
    }
  }
  cout<<"YES \n";
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
