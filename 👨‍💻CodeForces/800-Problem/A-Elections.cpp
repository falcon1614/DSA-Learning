#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;

    int maxi=max({a,b,c});
    if(a==maxi && a!=b && a!=c){
        cout<<0<<" "<<maxi-b+1<<" "<<maxi-c+1<<endl;
    }
    else if(b==maxi && b!=a && b!=c){
        cout<<maxi-a+1<<" "<<0<<" "<<maxi-c+1<<endl;
    }
    else if(c==maxi && c!=a && c!=b){
        cout<<maxi-a+1<<" "<<maxi-b+1<<" "<<0<<endl;
    }
    else{
        cout<<maxi - a + 1<<" "<<maxi - b + 1<<" "<<maxi - c + 1<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}