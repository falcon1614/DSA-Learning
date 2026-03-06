#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    unordered_map<int,int> mp;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }

    int score = 0;

    for(auto it : mp){
        score += it.second / 2;
    }

    cout << score << "\n";
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
