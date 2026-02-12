#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
  if(b == 0){
    return a;
  }
  else{
    return gcd(b,a%b);
  }
}
void solve() {
  long long a, b;
  cin >> a >> b;

  if(b % a == 0) {
    cout << b * (b/a) <<"\n";
  }
  else{
    cout << a * (b/gcd(a,b)) <<"\n";
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}
