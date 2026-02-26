#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void solve() {
    cin >> n >> m;

    graph.assign(n + 1, {});
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> reps;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            reps.push_back(i);
            dfs(i);
        }
    }

    cout << reps.size() - 1 << "\n";
    for (int i = 1; i < reps.size(); i++) {
        cout << reps[0] << " " << reps[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
