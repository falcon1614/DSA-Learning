// https://cses.fi/problemset/task/1094

#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> x(n);
  for(int i=0; i<=n; i++){
    cin>>x[i];
  }
  long long count = 0;
  long long prev = x[0];
  for(int i=1; i<n;i++){
    if(x[i]<prev){
      count += prev-x[i];
    }else{
      prev = x[i];
    }
  }
  cout<<count;
}

