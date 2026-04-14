#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n,k;
  cin >> n >> k;

  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  vector<int> p(k);
  for(int i=0; i<k; i++){
    cin >> p[i];
  }

  int target_p = p[0] - 1;
  int target_val = a[target_p];

  // left side
  int left_ops = 0;
  for(int i=0; i<= target_p; i++){
    int actual_val = (a[i] + left_ops) % 2;
    if(actual_val != target_val){
      left_ops++;
    }
  }

  // right side
  int right_ops = 0;
  for(int i=n-1; i> target_p; i--){
    int actual_val = (a[i] + right_ops) % 2;
    if(actual_val != target_val){
      right_ops++;
    }
  }

  int ans = max(left_ops, right_ops);
  if(ans % 2 != 0){
    ans++;
  }

  cout << ans << "\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
