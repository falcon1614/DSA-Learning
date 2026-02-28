#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;

  int count = 0;
  for(int i = 1; i<=n; i++){

    for(int j=1; j<=n; j++){

      if(i == (n-j)){
        count++;
      }
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
}
