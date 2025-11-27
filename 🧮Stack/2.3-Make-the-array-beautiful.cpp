// https://www.geeksforgeeks.org/problems/make-the-array-beautiful--170647/1
#include <bits/stdc++.h>
using namespace std;

vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int>s;
        for(int i=0; i<arr.size(); i++){
            if(s.empty()){
                s.push(arr[i]);
            }
            else if(arr[i]>=0){
                // Check Stack element non negative
                if(s.top()>=0){
                    s.push(arr[i]);
                }else{
                    s.pop();
                }
            }else{
                if(s.top()<0){
                    s.push(arr[i]);
                }else{
                    s.pop();
                }
            }
        }
        vector<int>ans(s.size());
        int i = s.size()-1;
        while(!s.empty()){
            ans[i] = s.top();
            s.pop();
            i--;
        }

        return ans;
}


int main() {
    vector<int> arr = {4, -2, -2, 3};

    vector<int> result = makeBeautiful(arr);

    int i = 0;
    while(i < result.size()) {
        cout << result[i] << endl;
        i++;
    }

    return 0;
}
