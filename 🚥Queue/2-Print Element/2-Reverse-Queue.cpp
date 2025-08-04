// https://www.geeksforgeeks.org/problems/queue-reversal/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Queue&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

// Function to reverse a queue
queue<int> reverseQueue(queue<int> &q) {
    stack<int> st;
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    return q;
}

int main() {
    queue<int> q;

    // Sample input
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    reverseQueue(q);

    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
