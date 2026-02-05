#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    int temp;
    cin>>temp;
    if(temp==1){
      cout<<"HARD"<<"\n";
      return;
    }
  }
  cout<<"EASY"<<"\n";
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
