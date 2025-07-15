// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
// https://www.geeksforgeeks.org/problems/next-greater-element/1
#include<bits/stdc++.h>
using namespace std;

// BrutForce Method
vector<int> large(vector<int>&arr){
  int n = arr.size();
  vector<int>ans(n,-1);

  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      // check if arr[j] is greater than arr[i]
      if(arr[j]>arr[i]){
        ans[i] = arr[j];
        break;
      }
    }
  }
  return ans;
}

// Optimized Stack Method
vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

// Utility function to print a vector
void printVector(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {0, 2, 3, 1, 1};

    cout << "Input Array: ";
    printVector(arr);

    cout << "Brute Force Output: ";
    vector<int> bf = large(arr);
    printVector(bf);

    cout << "Stack-Based Output: ";
    vector<int> st = nextGreaterElement(arr);
    printVector(st);

    return 0;
}
