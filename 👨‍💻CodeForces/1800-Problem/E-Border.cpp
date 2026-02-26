// https://codeforces.com/contest/1011/problem/E%C3%A2%C2%81%C2%A3
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(b==0){
    return a;
  }
  return gcd(b,a%b);
}
void solve(){
  int n,k;
  cin>>n>>k;

  int g = 0;
  for(int i=0; i<n; i++){
    int t;
    cin>>t;
    g = gcd(g,t);
  }

  set<int> ans;
  for(int i=0; i<k; ++i){
    ans.insert((1ll*g*i)%k);
  }

  cout<<ans.size()<<"\n";
  for(auto it:ans){
    cout<<it<<" ";
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
