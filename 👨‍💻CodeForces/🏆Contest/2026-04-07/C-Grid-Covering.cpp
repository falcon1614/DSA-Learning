#include<bits/stdc++.h>
using namespace std;

void solve(){
  long long n,  m,  a,  b;
  cin >>  n >>  m >>  a >>  b;

  if( gcd(a, n) == 1 && gcd(b, m) == 1 && gcd(n, m) <= 2){
    cout <<"YES \n";
  }
  else{
    cout <<"NO \n";
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
