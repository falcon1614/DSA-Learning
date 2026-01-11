#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int even_misplaced=0, odd_misplaced=0;
    for(int i=0;i<n;i++){
        if(i%2!=arr[i]%2){
            if(i%2==0) even_misplaced++;
            else odd_misplaced++;
        }
    }
    if(even_misplaced==odd_misplaced){
        cout<<even_misplaced<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}