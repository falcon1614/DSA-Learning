#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n,k;
  cin>>n>>k;
  vector<int> ans(n);
  for(int i=0; i<n; i++){
    cin>>ans[i];
  }

  if(find(ans.begin(),ans.end(),k) != ans.end()){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
