#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n,m;
  cin>>n>>m;

  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin>>a[i];
  }

  long long same = 1;
  for(int i=1; i<n; i++){
    if(a[i] == a[i-1]){
      same++;
    }
    else{
      same = 1;
    }

    if(same >= m){
      cout <<"NO \n";
      return;
    }
  }

  cout <<"YES \n";
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
