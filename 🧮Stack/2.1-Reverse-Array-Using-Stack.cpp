// https://leetcode.com/problems/reverse-string/submissions/1677021355/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void reverseString(vector<char>& s) {
    stack<char> st; // stack of chars, not ints
    for(int i = 0; i < s.size(); i++) {
        st.push(s[i]);
    }

    int i = 0;
    while(!st.empty()) {
        s[i] = st.top();
        st.pop();
        i++;
    }
}

int main() {
    vector<char> s = {'a', 'd', 'v', 'g', 'h', 'j', 'd'};

    reverseString(s);

    // Print reversed string
    for(char c : s) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
