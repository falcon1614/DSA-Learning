// https://codeforces.com/problemset/problem/472/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if(n % 2 == 0){
        cout << 4 << " " << n - 4 << "\n";
    }
    else{
        cout << 9 << " " << n - 9 << "\n";
    }

    return 0;
}
