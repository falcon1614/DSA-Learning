#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    if(n % 4 != 0){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;

        int sum_even = 0, sum_odd = 0;

        // Print even numbers
        for(int i = 2; i <= n; i += 2){
            cout << i << " ";
            sum_even += i;
        }

        // Print odd numbers except last
        for(int i = 1; i < n - 1; i += 2){
            cout << i << " ";
            sum_odd += i;
        }

        // Print last odd number to balance sum
        cout << sum_even - sum_odd << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
