// https://cses.fi/problemset/task/1669
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> parents;
vector<bool> visited;
int cycle_start = -1;
int cycle_end;

bool dfs(int node, int parent){
    visited[node] = true;

    for(auto neighbour: graph[node]){

        if(neighbour == parent) continue;

        if(visited[neighbour]){
            cycle_start = neighbour;
            cycle_end = node;
            return true;
        }
        else{
            parents[neighbour] = node;
            if(dfs(neighbour, node)) return true;
        }
    }

    return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  cin>>n>>m;
  graph.resize(n+1);
  parents.assign(n+1, -1);
  visited.assign(n+1, false);

  // Build Adj List
  for(int i=0; i<n; i++){
    int u,v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // Run DFS on Disconnected component too
  for(int i=1; i<=n; i++){
    if(!visited[i] && dfs(i, -1)) break;
  }

  if(cycle_start == -1){
    cout<<"IMPOSSIBLE"<<"\n";
  }
  else{
    vector<int> cycle;
    cycle.push_back(cycle_start);
    int curr = cycle_end;

    while(curr != cycle_start){
      cycle.push_back(curr);
      curr = parents[curr];
    }

    // close Cycle
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() <<"\n";
    for(auto it:cycle){
      cout << it <<" ";
    }
    cout<<"\n";
  }
  return 0;
}


/*
  **************************** Common Question ******************************************
  1. Why Check Neighbour != Parents         To Ignore the edge that leads back to parents
  2. Why Not use BFS                        DFS easy for Backtracking
  3. What if the graph is disconnected      We Check Each Components
  4. Why reverse the cycle at the end       Because we track it backward using parents
  5. Can there be more than one cycle       Yes, but the problem only ask for any one

  *************************** Generalization ********************************************
  1. Cycle detection in other Graph
  2. Tree Validation
  3. Connected Components With Cycle
  4. DFS with Back Edge
  
*/
