#include<bits/stdc++.h>
using namespace std;

// n -> row  m -> column
int n, m;

vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int u, int v, vector<vector<char>> &grid, vector<vector<bool>> &visited){

  visited[u][v] = true;
  for(auto [dx,dy]:direction){
    int nextU = u+dx;
    int nextV = v+dy;

    // Check if the next cell is within bounds is a flour '.' and not visited
    if(nextU >= 0 && nextU < n && nextV >=0 && nextV < m && grid[nextU][nextV] == '.' && !visited[nextU][nextV]){
        dfs(nextU,nextV,grid,visited);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  cin >> m;

  vector<vector<char>> grid(n,vector<char>(m));
  vector<vector<bool>> visited(n,vector<bool>(m,false));

  //  Take Input
  for(int u=0; u<n; u++){
    for(int v=0; v<m; v++){
      cin>>grid[u][v];
    }
  }

  // Visited Every Node
  int count = 0;
  for(int u=0; u<n; u++){
    for(int v=0; v<m; v++){
      if(grid[u][v]=='.' && !visited[u][v]){
        dfs(u,v,grid,visited);
        count++;
      }
    }
  }

  cout << count <<endl;
  return 0;
}
