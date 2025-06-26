#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack))
                return true;
        } else if (recStack[neighbor]) {
            return true; // Cycle found
        }
    }

    recStack[node] = false;
    return false;
}

bool hasCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 4; // Number of vertices
    vector<int> adj[V];

    // Add directed edges
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // This edge creates a cycle

    if (hasCycle(V, adj))
        cout << "Cycle detected in the graph.\n";
    else
        cout << "No cycle in the graph.\n";

    return 0;
}
