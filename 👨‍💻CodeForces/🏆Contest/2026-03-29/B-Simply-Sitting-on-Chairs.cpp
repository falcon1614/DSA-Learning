#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> marked(n,0);
    int ans = 0;
    int count = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;

        if(x > i){
            marked[x-1] = -1;
        }

        count += marked[i-1];
        ans = max(ans, count+i);
    }

    cout << ans << "\n";
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
