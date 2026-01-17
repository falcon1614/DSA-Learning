#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int count = 0;
    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            if(2*i+4*j==n){
                count++;
            }
        }
    }
    cout<<count<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
