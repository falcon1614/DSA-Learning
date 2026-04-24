#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());

    // Leftmost maximum
    int maxPos = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == mx){
            maxPos = i;
            break;
        }
    }

    // Rightmost minimum
    int minPos = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] == mn){
            minPos = i;
            break;
        }
    }

    int ans = maxPos + (n - 1 - minPos);

    // If max comes before min, one overlap happens
    if(maxPos > minPos) ans--;

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
