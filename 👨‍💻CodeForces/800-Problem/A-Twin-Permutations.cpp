#include<bits/stdc++.h>
using namespace std;

void solve(){
  long long n;
  cin>>n;

  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin>>a[i];
  }

  // (n - element) + 1
  vector<int> ans(n);
  for(int i=0; i<n; i++){
    int temp = (n - a[i]) + 1;
    ans[i] = temp;
  }

  // print
  for(int i=0; i<n; i++){
    cout<<ans[i]<<" ";
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
