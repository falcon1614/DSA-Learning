#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n,q;
  cin>>n>>q;
  vector<int> a,b;

  for(int i=0; i<n; i++){
    cin>>a[i];
  }

  for(int i=0; i<n; i++){
    cin>>b[i];
  }

  vector<pair<int,int>> qu;
  for(int i = 0; i < q; i++){
    int q1, q2;
    cin >> q1 >> q2;
    qu.push_back({q1, q2});
    
  }


}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
