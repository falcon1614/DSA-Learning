#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b){

  while(b != 0){
    long long temp = a;
    a = b;
    b = temp%b;
  }
  return a;
}
void solve(){
  long long a, b, k;
  cin>> a >> b >> k;

  long long g = gcd(a,b);

  if(max(a/g, b/g) <= k){
    cout<< 1 <<"\n";
  }
  else{
    cout<< 2 <<"\n";
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
