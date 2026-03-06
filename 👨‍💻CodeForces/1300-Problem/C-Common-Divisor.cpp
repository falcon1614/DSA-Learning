#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    while(b != 0){
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long countDivisor(long long x){
    long long ans = 1;
    for(long long i = 2; i * i <= x; i++){
        int cnt = 0;
        while(x % i == 0){
            x /= i;
            cnt++;
        }
        ans *= (cnt + 1);
    }

    if(x > 1) ans *= 2;

    return ans;
}

void solve(){
    long long n;
    cin >> n;

    vector<long long> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long g = 0;
    for(int i = 0; i < n; i++){
        g = gcd(g, a[i]);
    }

    cout << countDivisor(g) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
