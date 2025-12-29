#include<bits/stdc++.h>
using namespace std;
int main(){
  int V;
  cin>>V;
  vector<vector<int>> adj(V, vector<int>(V));
  
  for(int i=0; i<V; i++){
    for(int j=0; j<V; j++){
      cin>>adj[i][j];
    }
  }
  return 0;
}

// Adjacency Matrix

