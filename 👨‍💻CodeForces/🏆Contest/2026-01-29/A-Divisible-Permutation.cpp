#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    int count_1 = n;
    for(int i = n-1; i >= 0; i -= 2){
        a[i] = count_1;
        count_1--;
    }

    int count = 1;
    for(int i = n-2; i >= 0; i -= 2){
        a[i] = count;
        count++;
    }

    for(auto it : a){
        cout << it << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


