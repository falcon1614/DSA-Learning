// https://codeforces.com/problemset/problem/1806/A
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // If target y (d) is below current y (b)
    // we cannot move downward, so answer is impossible
    if(d < b){
        cout << -1 << "\n";
        return;   // exit this test case
    }

    // First move vertically from b to d
    int move = d - b;

    // When we move up, x also increases by the same amount
    a += move;

    // If target x (c) is greater than our new x (a)
    // we cannot move right, only left is allowed
    if(c > a){
        cout << -1 << "\n";
        return;   // exit this test case
    }

    // Move left to reach c
    move += (a - c);

    // Total moves required
    cout << move << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  

    // Solve each test case
    while(t--){
        solve();
    }
}
