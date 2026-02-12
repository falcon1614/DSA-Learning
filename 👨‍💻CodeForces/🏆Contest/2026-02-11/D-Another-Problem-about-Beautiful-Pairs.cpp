#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;

  vector<int> a(n+1);
  for(int i=1; i<=n; i++){
    cin>>a[i];
  }

  long long ans = 0;
  int b = sqrt(n);

  for(int i=1; i<=b; i++){
    for(int j=1; j<=n; j++){
      long long prod = 1ll * i * a[j];
      if(prod < j){
        int k = j - prod;
        if(a[k] == i ) ans++;
      }
    }
  }

  for(int i=1; i<=n; i++){
    if(a[i] > b){
      long long ai = a[i];
      if(ai >= n) continue;

      for(int k=1;; k++){
        long long j = i + ai * k;
        if(j>n) break;
        if(a[j]==k) ans++;
      }
    }
  }
  cout<<ans<<"\n";
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
