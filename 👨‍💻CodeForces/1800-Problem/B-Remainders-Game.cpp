// https://codeforces.com/contest/687/problem/B%C3%A2%C2%81%C2%A3
#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n,k;
  cin>>n>>k;
  vector<int> c(n);
  for(int i=0; i<n; i++){
    cin>>c[i];
  }

  long long L = 1;
  for(int i=0; i<n; i++){
    long long g = gcd(L,c[i]);

    long long mul = c[i]/g;
    L = (L * mul) % k;

    if(L%k == 0){
      cout<<"Yes \n";
      return;
    }
  }

  if(L%k==0){
    cout<<"Yes \n";
  }
  else{
    cout<<"No \n";
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
