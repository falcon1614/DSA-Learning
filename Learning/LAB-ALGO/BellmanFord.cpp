#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Edge structure: (u -> v with weight w)
struct Edge {
    int u, v, w;
};

void bellmanFord(int V, int E, int src, vector<Edge>& edges) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges (V - 1) times
    for (int i = 1; i <= V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < E; ++j) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source " << src << "\n";
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX)
            cout << i << "\tINF\n";
        else
            cout << i << "\t" << dist[i] << "\n";
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    bellmanFord(V, E, src, edges);

    return 0;
}
