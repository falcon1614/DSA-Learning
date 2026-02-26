// https://codeforces.com/contest/2202/problem/A
#include<bits/stdc++.h>
using namespace std;
void solve(){
  int x, y;
  cin>> x >> y;

  long long curr = 0;
  if(y<0){
     curr += (-1*y)*4;
  }
  else{
      curr += 2*y;
  }

  if(curr <= x && ((x-curr)%3 == 0)){
      cout<<"YES \n";

  }else{
      cout<<"NO \n";
  }

}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
