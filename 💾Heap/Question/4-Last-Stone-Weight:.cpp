// https://leetcode.com/problems/last-stone-weight/submissions/1718003252/?source=submission-ac

#include <bits/stdc++.h>
using namespace std;

// Function to compute the last stone weight
int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> p;

    for (int i = 0; i < stones.size(); i++) {
        p.push(stones[i]);
    }

    while (p.size() > 1) {
        int weight = p.top();
        p.pop();
        weight -= p.top();
        p.pop();
        if (weight > 0) {
            p.push(weight);
        }
    }

    return p.empty() ? 0 : p.top();
}

int main() {
    int n;
    cout << "Enter number of stones: ";
    cin >> n;

    vector<int> stones(n);
    cout << "Enter the stone weights: ";
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    int result = lastStoneWeight(stones);
    cout << "Last stone weight: " << result << endl;

    return 0;
}
