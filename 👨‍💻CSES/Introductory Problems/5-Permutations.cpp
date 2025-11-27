// https://cses.fi/problemset/task/1070
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    if(n==2 || n==3){
        cout<<"NO SOLUTION";
        return 0;
    }

    // Print even
    for(int i=2; i<=n; i=i+2){
        cout<<i<<" ";
    }
    // Print odd
    for(int i=1; i<=n; i=i+2){
        cout<<i<<" ";
    }
    return 0;
}
