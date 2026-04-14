#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n,k;
  cin >>  n >> k;

  long long total_sum = 0;
  for(int i=0; i<n; i++){
    int temp;
    cin>>temp;
    total_sum += temp;
  }

  long long special_sum = n*k;

  if(total_sum %2 != 0 || special_sum % 2 == 0){
    cout << "YES \n";
  }
  else{
    cout <<"NO \n";
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
  return 0;
}
