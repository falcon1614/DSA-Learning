#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n,m;
  cin>>n>>m;

  string x,s;
  cin>>x;
  cin>>s;

  int count = 0;
  while(x.size()<=200){
    if(x.find(s) != string::npos){
      cout<<count<<endl;
      return;
    }
    else{
      x+=x;
      count++;
    }
  }
  cout<< -1 <<endl;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
