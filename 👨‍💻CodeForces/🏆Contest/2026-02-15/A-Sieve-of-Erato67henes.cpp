#include<bits/stdc++.h>
using namespace std;
void solve(){
  long long n;
  cin>>n;

  bool found67 = false;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 67 ) {
        found67 = true;
    }
  }
    cout << (found67 ? "YES\n" : "NO\n");
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
