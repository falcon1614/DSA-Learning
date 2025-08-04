#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];  // Ensure this is large enough for your test cases

int knapSack(int wt[], int val[], int W, int n){
    // Base case
    if(n == 0 || W == 0){
        return dp[n][W] = 0;
    }

    // Already calculated
    if(dp[n][W] != -1) return dp[n][W];

    if(wt[n-1] <= W){
        return dp[n][W] = max(val[n-1] + knapSack(wt, val, W - wt[n-1], n - 1),knapSack(wt, val, W, n - 1));
    }
    else if (wt[n-1] > W){
        return dp[n][W] = knapSack(wt, val, W, n - 1);
    }
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

        // Reset dp array to -1
        memset(dp, -1, sizeof(dp));

        int result = knapSack(wt, val, W, n);
        cout << "Maximum value in Knapsack: " << result << endl;
    }

    return 0;
}
