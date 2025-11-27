#include <bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string text1, string text2) {
    vector<int> dp(text1.length(), 0);
    int longest = 0;

    for (char c : text2) {
        int curLength = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (curLength < dp[i]) {
                curLength = dp[i];
            } else if (c == text1[i]) {
                dp[i] = curLength + 1;
                longest = max(longest, curLength + 1);
            }
        }
    }

    return longest;        
}
int main(){
    string text1;
    string text2;
    cin>>text1>>text2;
    int h=longestCommonSubsequence(text1,text2);
    cout<<h;
    cout<<endl;
}