#include<iostream>
#include<vector>
using namespace std;
// Adjacency Matrix
// Undirected unweight graph
int main(){
    int vertex, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertex;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // Create an adjacency matrix
    vector<vector<bool>>AdjMat(edges,vector<bool>(vertex,0));

    // U and V are edge joint
    int u,v;
    for(int i=0; i<edges; i++){
        cin >> u >> v;
        AdjMat[u][v] = 1;
        AdjMat[v][u] = 1;
    }
    // Print Matrix
    for(int i=0; i<vertex; i++){
        for(int j=0; j<vertex; j++){
            cout << AdjMat[i][j] <<" ";
        }
        cout << endl;
    }
}
