#include <iostream>
#include <vector>
using namespace std;

int knapsack(int n, int W, vector<int>& weights, vector<int>& values) {
    // Create a 2D DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Either take the item or leave it
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]],
                               dp[i - 1][w]);
            } else {
                // Can't take this item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // Max value with full capacity
}

int main() {
    int n = 4; // Number of items
    int W = 7; // Capacity of knapsack

    vector<int> weights = {1, 3, 4, 5};
    vector<int> values = {1, 4, 5, 7};

    int maxProfit = knapsack(n, W, weights, values);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}