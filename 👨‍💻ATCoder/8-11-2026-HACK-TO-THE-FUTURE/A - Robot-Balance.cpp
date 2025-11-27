#include<bits/stdc++.h>
using namespace std;

void solve(){
    int Head;
    int Body;
    cin>>Head;
    cin>>Body;
    if(Head>Body){
        cout << Head-Body;
    }
    else
    {
        cout<<0;
    }

}
int main(){
    solve();
    return 0;
}
