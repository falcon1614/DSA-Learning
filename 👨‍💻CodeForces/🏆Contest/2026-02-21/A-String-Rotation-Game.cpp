#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Count blocks
    int blocks = 1;
    for(int i = 1; i < n; i++){
        if(s[i] != s[i-1]){
            blocks++;
        }
    }

    // If all characters same
    if(blocks == 1){
        cout << 1 << "\n";
        return;
    }

    // If first and last are same
    if(s[0] == s[n-1]){
        cout << blocks  << "\n";
    }
    else{
        cout << min(n,blocks + 1) << "\n";
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
