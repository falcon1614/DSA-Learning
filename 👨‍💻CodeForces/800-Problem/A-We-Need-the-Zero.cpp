#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    int xr = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        xr ^= x;
    }

    if(n % 2 == 1){
        cout << xr << "\n";
    }
    else{
        if(xr == 0) cout << 0 << "\n";
        else cout << -1 << "\n";
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
}
