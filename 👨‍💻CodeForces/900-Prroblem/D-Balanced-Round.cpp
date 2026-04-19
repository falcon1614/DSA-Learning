#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n,k;
  cin>>n>>k;

  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin>>a[i];
  }

  if(n == 1) {
    cout << 0 <<"\n";
    return;
  }

  sort(a.begin(), a.end());

  int curr = 1;
  int ans = 0;
  for(int i=1; i<n; i++){
    if(abs(a[i] - a[i-1]) <= k){
      curr++;
    }
    else{
      curr=1;
    }

    ans = max(ans,curr);
  }

  cout << n - ans <<"\n";
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
