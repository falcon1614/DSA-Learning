#include <bits/stdc++.h>
using namespace std;
int sum(long long n){
    int digit_sum = 0;
    while(n){
        digit_sum += n%10;
        n/=10;
    }
    return digit_sum;
}
void solve() {
    long long n;
    cin >> n;

    int count = 0;
    for(long long i=n+1; i<= n+90; i++){
        if(i- sum(i) == n){
            count++;
        }
    }

    cout<<count<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
