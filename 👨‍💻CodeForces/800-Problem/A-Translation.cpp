#include<bits/stdc++.h>
using namespace std;
void solve(){
  string s,t;
  cin>>s>>t;

  int start=0;
  int end = s.size()-1;
  while(start<end){
    swap(s[start],s[end]);
    start++;
    end--;
  }

  if(s==t){
    cout<<"YES \n";
  }
  else{
    cout<<"NO \n";
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
