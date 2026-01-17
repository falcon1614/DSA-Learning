#include<bits/stdc++.h>
using namespace std;

void solve(){
    int ratring;
    cin>>ratring;

    if(ratring <= 1399){
        cout<<"Division 4"<<endl;
    }
    else if (1400 <= ratring && ratring <= 1599) {
        cout<<"Division 3"<<endl;
    }
    else if (1600 <= ratring && ratring <= 1899) {
        cout<<"Division 2"<<endl;
    }
    else {
        cout<<"Division 1"<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}