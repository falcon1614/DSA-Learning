#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> edgelist = {{0, 1}, {1, 2}, {2, 3}, {3, 4},
                                       {4, 5}, {5, 6}, {6, 7}};
    unordered_map<int, vector<int>> adj;

    // Building adjacency list
    for (int i = 0; i < edgelist.size(); i++) {
        int u = edgelist[i][0];
        int v = edgelist[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS initialization
    stack<int> s;
    vector<bool> visited(8, false);  // Correct size for nodes 0-7

    // Start from node 5
    s.push(5);
    visited[5] = true;

    cout << "DFS Traversal of graph: ";

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << node << " ";

        // Process neighbors in reverse order for standard DFS sequence
        reverse(adj[node].begin(), adj[node].end());
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }

    cout << endl;
    return 0;
}
