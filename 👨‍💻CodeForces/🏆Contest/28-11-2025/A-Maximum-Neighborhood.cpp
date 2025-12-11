#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int sum1 = 0;
    for(int i=(n*n-n+1); i<n*n; i++){
        sum+=i;
    }
    cout<<sum1<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
