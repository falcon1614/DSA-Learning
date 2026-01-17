// https://codeforces.com/problemset/problem/1527/A
#include<bits/stdc++.h>
using namespace std;

void solve(){
  long long n;
  cin>>n;

  long long x = n;
  while(x>0){
    n-=1;
    x&=n;
  }
  cout<<n<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
