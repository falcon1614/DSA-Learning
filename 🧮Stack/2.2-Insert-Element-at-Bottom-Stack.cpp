// https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1?page=2&category=Stack&difficulty=Easy&sortBy=submissions
#include<bits/stdc++.h>
using namespace std;

// Function to insert an element at the bottom of a stack
stack<int> insertAtBottom(stack<int> st, int x) {
    stack<int> temp;

    // Step 1: Move all elements from original stack to temp
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }

    // Step 2: Push the new element onto the now-empty stack
    st.push(x);

    // Step 3: Push all elements back from temp to original stack
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }

    return st;
}

int main(){
    stack<int> st;

    // Add some elements
    st.push(10);
    st.push(20);
    st.push(30);

    // Insert 5 at the bottom
    st = insertAtBottom(st, 5);

    // Print stack content (top to bottom)
    cout << "Stack from top to bottom: ";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
