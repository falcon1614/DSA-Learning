// https://www.geeksforgeeks.org/problems/print-bracket-number4058/1?page=1&difficulty%5B%5D=0&category%5B%5D=Stack&sortBy=submissions
#include<bits/stdc++.h>
using namespace std;
vector<int> bracketNumbers(string str) {
    // Your code goes here
    int count = 0;
    stack<int>st;
    vector<int>ans;
    for(int i=0; i<str.size(); i++){
        // Opening Bracket
            if(str[i]=='('){
                count++;
                st.push(count);
                ans.push_back(count);
            }
        // Closing Bracket
        else if(str[i]==')'){
            ans.push_back(st.top());
            st.pop();
        }
    }
    return ans;
}

int main() {
    string str;
    cout << "Enter a string with brackets: ";
    cin >> str;

    vector<int> result = bracketNumbers(str);

    cout << "Bracket numbers: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
