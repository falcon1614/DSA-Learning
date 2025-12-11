#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,y,r;
    cin>>n;
    cin>>y>>r;
    int y_rem = y/2;
    int r_rem = r/1;
     int ans = min(n, y_rem+r_rem);
    cout << ans << endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
