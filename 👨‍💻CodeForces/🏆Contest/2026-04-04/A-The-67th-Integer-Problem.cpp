#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x;
    cin >> x;

    if(x == 67) cout << 67 << "\n";
    else cout << x + 1 << "\n";
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
