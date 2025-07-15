// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/submissions/1678077345/?source=submission-ac
#include<bits/stdc++.h>
using namespace std;
int minAddToMakeValid(string s) {
        stack<char>st;
        int count = 0;

        for(int i=0;i<s.size();i++)
        {
            // Opening
            if(s[i]=='(')
            st.push(s[i]);
            // closing
            else
            {
                if(st.empty())
                count++;
                else
                st.pop();
            }
        }

        return count +st.size();
}
int main(){
    string s = "((())";
    cout<<minAddToMakeValid(s)<<endl;
    return 0;
}
