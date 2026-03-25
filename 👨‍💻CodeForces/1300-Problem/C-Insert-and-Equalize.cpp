// https://codeforces.com/contest/1902/problem/C%E2%81%A3
#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin>>n;

  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin>>a[i];
  }

  //  n = 1
  if(n == 1){
    cout << 1 <<"\n";
  }

  sort(a.begin(), a.end());

  // Compute GCD of adjacent difference
  long long x = 0;
  for(int i=0; i<n; i++){
    x = gcd(x, a[i] - a[i-1]);
  }

  if(x==0) x = 1;
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
