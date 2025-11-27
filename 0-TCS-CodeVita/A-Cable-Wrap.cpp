#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[y] = x;
            rank[x]++;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int total_switches = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && (grid[i][j] == 'C' || grid[i][j] == 'R')) {
                vector<pair<int, int>> comp;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    comp.push_back({x, y});
                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] &&
                            (grid[nx][ny] == 'C' || grid[nx][ny] == 'R')) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }

                bool has_c = false;
                for (auto [x, y] : comp) {
                    if (grid[x][y] == 'C') {
                        has_c = true;
                        break;
                    }
                }
                if (!has_c) {
                    continue;
                }

                map<pair<int, int>, int> idx_map;
                int comp_size = comp.size();
                for (int k = 0; k < comp_size; k++) {
                    idx_map[comp[k]] = k;
                }

                UnionFind uf(comp_size);
                vector<bool> added(comp_size, false);
                vector<pair<int, int>> R_list;

                for (int k = 0; k < comp_size; k++) {
                    int x = comp[k].first, y = comp[k].second;
                    if (grid[x][y] == 'C') {
                        added[k] = true;
                    } else {
                        R_list.push_back({x, y});
                    }
                }

                for (int k = 0; k < comp_size; k++) {
                    if (grid[comp[k].first][comp[k].second] != 'C') continue;
                    for (int d = 0; d < 4; d++) {
                        int nx = comp[k].first + dx[d];
                        int ny = comp[k].second + dy[d];
                        auto it = idx_map.find({nx, ny});
                        if (it != idx_map.end() && grid[nx][ny] == 'C') {
                            uf.unite(k, it->second);
                        }
                    }
                }

                for (auto [x, y] : R_list) {
                    int k = idx_map[{x, y}];
                    if (added[k]) continue;
                    map<int, int> root_count;
                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        auto it = idx_map.find({nx, ny});
                        if (it != idx_map.end() && added[it->second]) {
                            int root = uf.find(it->second);
                            root_count[root]++;
                        }
                    }
                    bool can_add = true;
                    for (auto [root, count] : root_count) {
                        if (count > 1) {
                            can_add = false;
                            break;
                        }
                    }
                    if (can_add) {
                        added[k] = true;
                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];
                            auto it = idx_map.find({nx, ny});
                            if (it != idx_map.end() && added[it->second]) {
                                uf.unite(k, it->second);
                            }
                        }
                    } else {
                        total_switches++;
                    }
                }
            }
        }
    }

    cout << total_switches << endl;
    return 0;
}
