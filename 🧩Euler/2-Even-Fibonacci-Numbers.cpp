#include<bits/stdc++.h>
using namespace std;
int main(){
    long long  ans = 0;
    long long prev = 1;
    long long curr = 2;
    while(curr<4000000){
        if(curr%2==0){
            ans+=curr;
        }
        long long temp = curr;
        curr += prev;
        prev = temp;
    }
    cout<<ans;
    return 0;
}
