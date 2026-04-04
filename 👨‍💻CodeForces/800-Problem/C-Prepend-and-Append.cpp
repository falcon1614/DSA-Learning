#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin>>n;
  string str;
  cin>>str;

  int start = 0;
  int end = n-1;
  int count = 0;
  while(start < end && str[start] != str[end]){
    start++;
    end--;
  }

  cout << end - start + 1 <<"\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
