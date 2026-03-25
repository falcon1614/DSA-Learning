#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    int pos = 0, neg = 0;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 1) pos++;
        else neg++;
    }

    int ops = 0;

    while(pos < neg){
        pos++;
        neg--;
        ops++;
    }

    if(neg % 2 == 1){
        ops++;
    }

    cout << ops << "\n";
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
