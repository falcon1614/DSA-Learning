// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


#include <bits/stdc++.h>
using namespace std;

// Function to find the celebrity
int celebrity(vector<vector<int>>& M, int n) {
    stack<int> st;

    // Push all people onto stack
    for (int i = 0; i < n; i++) {
        st.push(i);
    }

    // Eliminate non-celebrities
    while (st.size() > 1) {
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();

        if (M[first][second]) {
            // first knows second → first cannot be celebrity
            st.push(second);
        } else {
            // first does NOT know second → second cannot be celebrity
            st.push(first);
        }
    }

    if (st.empty()) {
        return -1; // No celebrity
    }

    int candidate = st.top();

    // Verify the candidate
    int rowSum = 0, colSum = 0;
    for (int i = 0; i < n; i++) {
        rowSum += M[candidate][i];
        colSum += M[i][candidate];
    }

    if (rowSum == 0 && colSum == n - 1) {
        return candidate;
    } else {
        return -1;
    }
}

int main() {
    vector<vector<int>> M = {
        {0, 1, 1},
        {0, 0, 0},
        {0, 1, 0}
    };

    int n = M.size();

    int celeb = celebrity(M, n);

    if (celeb == -1) {
        cout << "No celebrity found.\n";
    } else {
        cout << "Celebrity is person " << celeb << endl;
    }

    return 0;
}
