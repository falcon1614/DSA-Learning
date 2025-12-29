#include<bits/stdc++.h>
using namespace std;
int main(){
  int V; // Vertex
  cin>>V;
  unordered_map<int,int> adj;
  for(int i=0; i<V; i++){
    cin>>adj[i];
  }
  return 0;
}
/*   eg
0 -> 1 2 3
1 -> 2 3 4 5
2 -> 2 4 6 7
3 -> 1 9 0 4 6
4 -> 1 4 6 8
*/
