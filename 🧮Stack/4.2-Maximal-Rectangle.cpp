// https://leetcode.com/problems/maximal-rectangle/submissions/1698306644/

// Maximal Rectangle --> convert to Largest Rectangle in Histogram
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

// Function to find Largest Rectangle in Histogram
int LRectangle(vector<int>& heights) {
    int n = heights.size();
    vector<int> Right(n);
    vector<int> Left(n);
    stack<int> st;

    // Right Nearest Smaller Element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            Right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        Right[st.top()] = n;
        st.pop();
    }

    // Left Nearest Smaller Element
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            Left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        Left[st.top()] = -1;
        st.pop();
    }

    // Calculate maximum area
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = Right[i] - Left[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

// Function to find the maximal rectangle in binary matrix
int MaximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;

    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> heights(col, 0);
    int ans = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == '0') {
                heights[j] = 0; // Reset height if '0'
            } else {
                heights[j] += 1; // Increment height if '1'
            }
        }
        ans = max(ans, LRectangle(heights)); // Use the LRectangle function to find max area
    }
    return ans;
}

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << "Maximal Rectangle Area: " << MaximalRectangle(matrix) << endl;

    return 0;
}

