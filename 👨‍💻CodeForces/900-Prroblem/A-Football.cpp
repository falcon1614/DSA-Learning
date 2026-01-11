#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int maxCount = 1;
    int currCount = 1;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            currCount++;
            maxCount = max(maxCount, currCount);
        } else {
            currCount = 1;
        }
    }

    if (maxCount >= 7)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
