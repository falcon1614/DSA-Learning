#include <bits/stdc++.h>
using namespace std;

bool DFS(unordered_map<int, vector<int>> &adj,int u,vector<bool> &visited,int parents) {

    visited[u] = true;

    for (int i = 0; i < adj[u].size(); i++) {

        int v = adj[u][i];

        if (v == parents) continue;

        if (visited[v]) return true;

        if (DFS(adj, v, visited, u)) {
            return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {

    unordered_map<int, vector<int>> adj;

    // undirected graph build
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);

    // check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i] && DFS(adj, i, visited, -1)) {
            return true;
        }
    }

    return false;
}

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    if (isCycle(V, edges)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
