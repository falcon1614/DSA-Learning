#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin>>n;
  int count = 0;
  while(n>1){
    if(n%6==0){
      count++;
      n/=6;
    }
    else if(n*2 % 6 == 0){
      count++;
      n=(n*2);
    }
    else{
      cout<<-1<<"\n";
      return;
    }
  }
  cout<<count<<"\n";
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
