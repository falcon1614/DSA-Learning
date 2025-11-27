#include<bits/stdc++.h>
// 600851475143
using namespace std;
int main(){
    long long largest_prime_factor = 600851475143;
    long long temp  = largest_prime_factor;
    int ans=0;
    while (temp>1){
        for(int i=2; i<=sqrt(largest_prime_factor); i++){
            if(temp%i==0){
                ans=max(ans,i);
                temp/=i;
            }
    }
}
    cout<<ans;
    return 0;
}
