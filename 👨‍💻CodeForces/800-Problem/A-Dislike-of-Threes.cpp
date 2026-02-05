#include<bits/stdc++.h>
using namespace std;
void solve(){
  long long k;
  cin>>k;
  long count = 0;
  long long i=1;
  while(count<k){
    if(i%3!=0 && i%10 !=3){
      count++;
    }
    i++;
  }
  cout<<i-1<<"\n";
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
