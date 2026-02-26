#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int count0 = 0, count1 = 0;

    for(char c : s) {
        if(c == '0') count0++;
        else count1++;
    }

    int t=0;
    for(char c : s){
      if(c == '0' && count1 > 0){
        count1--;
        t++;
      }
      else if(c == '1' && count0 > 0){
        count0--;
        t++;
      }
      else{
        break;
      }
    }

    cout<<n-t<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
