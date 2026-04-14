#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin>>n;

  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin>>a[i];
  }

  sort(a.rbegin(), a.rend());

  for(int i=1; i<n; i++){
    if(a[i] == a[i-1]){
      cout << -1 <<"\n";
      return;
    }
  }

  for(int &it: a){
    cout << it <<" ";
  }
  cout<<"\n";

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
