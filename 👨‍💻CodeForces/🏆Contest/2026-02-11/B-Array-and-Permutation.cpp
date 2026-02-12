#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n+1);
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        p[x] = i;
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> b;
    if(n>0) b.push_back(a[0]);
    for(int i=1; i<n; i++){
        if(a[i] != a[i-1]){
            b.push_back(a[i]);
        }
    }

    bool ok = true;
    for(int i=0; i+1<(int)b.size(); i++){
        if(p[b[i]] > p[b[i+1]]){
            ok = false;
            break;
        }
    }

    if(ok == true){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
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
