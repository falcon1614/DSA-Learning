//https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/1697539857/

// height*(NSR-NSL-1) = height*(right-left-1)
// Time Complexity: O(n)
// Space Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
int LRectangle(vector<int>& hights){
  int n = hights.size();
  vector<int> Right(n);
  vector<int> Left(n);
  stack<int> st;

  // Right Nearest Smaller Element
  for(int i=0; i<n; i++){
    while(!st.empty() && hights[st.top()] > hights[i]){
      Right[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  while(!st.empty()){
    Right[st.top()] = n;
    st.pop();
  }

  // Left Nearest Smaller Element
  for(int i=n-1; i>=0; i--){
    while(!st.empty() && hights[st.top()] > hights[i]){
      Left[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  while(!st.empty()){
    Left[st.top()] = -1;
    st.pop();
  }

  // Calculating the maximum area
  int maxArea = 0;
  for(int i=0; i<n; i++){
    maxArea = max(maxArea,hights[i]*(Right[i]-Left[i]-1));
  }
  return maxArea;
}

// MEthod 2 If Find Overall Maximum Area
// Time Complexity: O(n)
// Space Complexity: O(1)
int LRectangle2(vector<int>& hights){

  int n = hights.size();
  int ans = 0;
  stack<int> st;
  int index = 0;

  
  for(int i=0; i<n; i++){

    while(!st.empty() && hights[st.top()] < hights[i]){

      index = st.top();
      st.pop();
      if(!st.empty()){
        ans = max(ans, hights[index] * (i - st.top() - 1));
      }
      else{
        ans = max(ans, hights[index] * i);
      }
    }
    st.push(i);
  }

  while(!st.empty()){

    index = st.top();
    st.pop();
    if(!st.empty()){
      ans = max(ans, hights[index] * (n - st.top() - 1));
    }
    else{
      ans = max(ans, hights[index] * n);
    }
  }
  return ans;
}


int main(){
  vector<int> hights = {2,1,5,6,2,3};
  cout << "Largest Rectangle Area: " << LRectangle(hights) << endl;
  cout << "Largest Rectangle Area (Method 2): " << LRectangle2(hights) << endl;
  return 0;
}

