#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n, k;
  cin >> n >> k;

  vector<int> a(n), p(k);
  for(int &x : a) cin >> x;
  for(int &x : p) cin >> x;

  int tar = a[p[0] -1];
  int s = 0, m = 0, st = 0;

  for(int i=0; i<k; i++){

    int en = p[i] - 1;
    int cnt = 0;

    for(int j=st; j<= en; j++){
      if( (a[j] + cnt) % 2 != tar ){
        cnt++;
      }
    }

    s += cnt;
    m = max(m, cnt);
    st = en+1;
  }

  int cnt = 0;
  for(int j=st; j <= n; j++){
    int val = (j == n) ? tar : a[j];
    if( (val +cnt) % 2 != tar){
      cnt++;
    }
  }
    s += cnt;
    m = max(m, cnt);

    cout << max(s/2, m) <<"\n";
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
