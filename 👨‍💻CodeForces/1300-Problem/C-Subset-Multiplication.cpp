// https://codeforces.com/contest/2124/problem/C%C3%A2%C2%81%C2%A3

#include<bits/stdc++.h>
using namespace std;

void solve(){
  long long n;
  cin>>n;

  vector<long long> b(n);
  for(int i=0; i<n; i++){
    cin>>b[i];
  }

  long long g = 0;
  long long ans = 1;
  for(int i=n-1; i>=0; i--){
    g = gcd(g,b[i]);
    ans = lcm(ans, b[i] / g);
  }

  cout << ans <<"\n";
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
