vector<int> makeBeautiful(vector<int> arr) {
    stack<int> s;

    for(int i = 0; i < arr.size(); i++) {
        if(s.empty()) {
            s.push(arr[i]);
        }
        else if((arr[i] >= 0 && s.top() >= 0) || (arr[i] < 0 && s.top() < 0)) {
            // Same sign
            s.push(arr[i]);
        } else {
            // Opposite signs
            s.pop();
        }
    }

    // Stack to vector (reversed)
    vector<int> ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    reverse(ans.begin(), ans.end()); // Restore original order

    return ans;
}