#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string str1, str2;
    cin >> str1 >> str2;

    int p2 = 0;
    int p1 = (str1[0] != str2[0]);

    for(int i = 1; i < n; i++) {
        int curr = min(
            p1 + (str1[i] != str2[i]),
            p2 + (str1[i] != str1[i-1]) + (str2[i] != str2[i-1])
        );

        p2 = p1;
        p1 = curr;
    }

    cout << p1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
