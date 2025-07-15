// https://www.geeksforgeeks.org/problems/string-manipulation3706/1?page=1&difficulty%5B%5D=0&category%5B%5D=Stack&sortBy=submissions
#include <bits/stdc++.h>
using namespace std;

int removeConsecutiveSame(vector<string>& arr) {
        // Your code goes here
        stack<string>s;
        for(int i=0; i<arr.size(); i++){
            if(s.empty()){
                s.push(arr[i]);
            }
            else if(s.top()==arr[i]){
                s.pop();
            }
            else{
                s.push(arr[i]);
            }
        }
        return s.size();
}

int main(){
  
  return 0;
}
