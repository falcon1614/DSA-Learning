#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    if(n==2){
        cout<<"YES"<<endl;
    }
    else if(n==3){
        if(a[0]==a[1]||a[0]==a[2])
            cout<<"YES"<<endl;
    }
    for (int i = 1; i < n; i++)
    {
        if(a[0]!=a[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}
