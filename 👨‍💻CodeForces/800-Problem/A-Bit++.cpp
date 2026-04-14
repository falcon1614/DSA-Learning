#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;

  int x = 0;
  while(n--){
    string st;
    cin>>st;
    if(st.find("++") != string::npos){
        x++;
    } else {
        x--;
    }
  }

  cout << x <<"\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
