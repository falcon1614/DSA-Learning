#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  while(b){
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

void solve(){
  int n;
  cin >> n;

  int g = 0;
  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    g = gcd(g, temp);
  }

  if (g < n){
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
