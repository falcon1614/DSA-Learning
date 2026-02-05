#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    int mini = INT_MAX;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;

        if(temp == 0){
            cout<<0<<endl;
            return;
        }
        else if(abs(temp)>0){
            temp = abs(temp);
            mini = min(mini,temp);
        }
    }
    cout<<mini<<endl;
}
int main(){
    solve();
    return 0;
}
