#include<bits/stdc++.h>
using namespace std;

int calc(int a, int b, bool startWhite) {
    int layers = 0;
    long long size = 1;
    bool white = startWhite;

    while (true) {
        if (white) {
            if (a < size) break;
            a -= size;
        } else {
            if (b < size) break;
            b -= size;
        }
        layers++;
        size *= 2;
        white = !white;
    }
    return layers;
}

void solve(){
  int a,b;
  cin>>a>>b;

  int ans = max(calc(a, b, true), calc(a, b, false));
    cout << ans << '\n';
}

int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
