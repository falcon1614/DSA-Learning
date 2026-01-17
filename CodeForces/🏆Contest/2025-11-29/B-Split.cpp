#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    unordered_map<int,int>a(2*n);
    for(int i=0; i<2*n; i++){
        cin>>a[0];
    }
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" "<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
