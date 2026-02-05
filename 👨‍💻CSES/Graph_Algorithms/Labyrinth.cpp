#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Row n column m
  int n,m;
  cin>>n>>m;
  vector<vector<char>> grid(n,vector<char>(m));
  vector<vector<bool>> visited(n,vector<bool>(m,false));

  // Take Input
  for(int u=0; u<n; u++){
    for(int v=0; v<m; v++){
      cin>>grid[u][v];
    }
  }


}
