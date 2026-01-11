#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string ans = "";
    for (int i = 0; i < s.size(); ) {
        if (i + 2 < s.size() && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
            if (!ans.empty() && ans.back() != ' ')
                ans.push_back(' ');
            i += 3;
        } else {
            ans.push_back(s[i]);
            i++;
        }
    }

    cout << ans << endl;
    return 0;
}
