#include<bits/stdc++.h>
using namespace std;

int knapSack(int wt[], int val[], int W, int n){
  // Base Condition
  if(n==0 || W==0){
    return 0;
  }

  // Choice Diagram

  // wt select
  if(wt[n-1] <= W){
    return max(val[n-1]+knapSack(wt,val,W-wt[n-1],n-1),knapSack(wt,val,W,n-1));
  }
  // wt Not Select
  else if(wt[n-1]>W){
   return knapSack(wt,val,W,n-1);
  }
}

int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n, W;
        cin >> n >> W;  // Number of items and total capacity

        int wt[n], val[n];

        for (int i = 0; i < n; i++) {
            cin >> wt[i] >> val[i];  // Weight and value for each item
        }

        int result = knapSack(wt, val, W, n);
        cout << "Maximum value in Knapsack: " << result << endl;
    }

    return 0;
}
