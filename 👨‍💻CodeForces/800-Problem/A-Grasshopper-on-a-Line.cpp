#include<bits/stdc++.h>
using namespace std;

void solve(){
  long long x,k;
  cin>> x >> k;

  if(x %k != 0){
    cout << 1 <<"\n";
    cout << x<<"\n";
    return;
  }
  else{
    cout << 2 <<"\n";
    cout << x-1 <<" "<< 1 <<"\n";
    return;
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
