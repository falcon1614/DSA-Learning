#include<bits/stdc++.h>
using namespace std;

void solve(){

  int n;
  cin>>n;

  vector<int> a(n);
  for(int i=0; i<n; i++) cin>>a[i];

  int k=0;
  int totalops = 0;
  for(int i=0; i<n; i++){
    if(i==0 || a[i-1]%2 == a[i]%2) {
      k++;
    }
    else{
      totalops += k-1;
      k = 1;
    }
  }
  totalops += k-1;
  cout<<totalops<<"\n";
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
