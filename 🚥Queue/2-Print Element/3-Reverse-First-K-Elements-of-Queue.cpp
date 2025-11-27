// https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1?page=1&difficulty%5B%5D=0&category%5B%5D=Queue&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

// Function to reverse first k elements of a queue
queue<int> reverseFirstK(queue<int> q, int k) {
    stack<int> st;

    // Step 1: Push first k elements into stack
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Push them back to queue (in reversed order)
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move the remaining elements to back to keep their order
    int rem = q.size() - (q.size() - k);  // or simply: q.size() - k
    int total = q.size();
    for (int i = 0; i < total - k; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    int n, k;
    cout << "Enter number of elements in queue: ";
    cin >> n;

    cout << "Enter k (number of elements to reverse): ";
    cin >> k;

    cout << "Enter the elements of queue: ";
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    queue<int> result = reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}

