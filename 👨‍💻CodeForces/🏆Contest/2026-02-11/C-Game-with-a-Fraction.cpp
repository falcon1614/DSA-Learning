#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long p, q;
    cin >> p >> q;

    if(3*p >= 2*q && q > p){
        cout<<"Bob \n";
    }
    else{
        cout<<"Alice \n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
