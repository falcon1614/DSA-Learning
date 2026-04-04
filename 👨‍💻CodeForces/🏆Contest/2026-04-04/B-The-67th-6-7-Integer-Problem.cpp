#include<bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> a(7);
    int sum = 0;

    for(int i = 0; i < 7; i++){
        cin >> a[i];
        sum += a[i];
    }

    int mx = *max_element(a.begin(), a.end());

    int result = 2 * mx - sum;

    cout << result << "\n";
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
