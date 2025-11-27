#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];  // dp[i][j] = max value using first i items with capacity j

int knapSack(int wt[], int val[], int W, int n) {
    // Initialization of dp table
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= W; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    // Build the table iteratively
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++) {
            if(wt[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]],dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];  // Final answer
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, W;
        cin >> n >> W;

        int wt[n], val[n];
        for (int i = 0; i < n; i++) {
            cin >> wt[i] >> val[i];
        }

        int result = knapSack(wt, val, W, n);
        cout << "Maximum value in Knapsack: " << result << endl;
    }

    return 0;
}

