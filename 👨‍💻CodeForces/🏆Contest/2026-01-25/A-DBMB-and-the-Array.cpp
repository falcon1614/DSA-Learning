#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n, s, k;
  cin >> n >> s >> k;

  vector<int> a(n);
  long long total_sum = 0;
  for(int i=0; i<n; i++){
    int temp;
    cin>>temp;
    total_sum += temp;
    a.push_back(temp);
  }

  if(total_sum == s){
    cout<<"YES"<<"\n";
    return;
  }
  while(total_sum<s){
    total_sum += k;
    if(total_sum == s){
      cout<<"YES"<<"\n";
      return;
    }
  }
  cout<<"NO"<<"\n";
  return;
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
