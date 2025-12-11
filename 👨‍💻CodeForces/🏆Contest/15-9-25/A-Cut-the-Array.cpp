// https://codeforces.com/contest/2144/problem/A
#include<bits/stdc++.h>
using namespace std;

void cut(vector<int> arr, int n){
    int s1,s2,s3 = 0;
    // No of Element 3 
    if(n==3){
        s1 = arr[0]%3;
        s2 = arr[1]%3;
        s3 = arr[2]%3;
        if(s1!=s2!=s3||s1==s2==s3){
            cout <<1<<2;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        vector<int>arr(n+1);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cut(arr,n);
    }
    return 0;
}
