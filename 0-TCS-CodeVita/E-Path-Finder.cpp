#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> blocked;
int N, M;

vector<pair<int, int>> get_neighbors(int i, int j) {
    vector<pair<int, int>> res;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) continue;
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < N && nj >= 0 && nj < M && !blocked[ni][nj]) {
                res.push_back({ni, nj});
            }
        }
    }
    return res;
}

int compute_cost(int i, int j, int ni, int nj) {
    auto neighbors = get_neighbors(i, j);
    if (neighbors.empty()) return INT_MAX;

    // Find maximum value among neighbors
    int max_val = -1;
    for (auto [x, y] : neighbors) {
        max_val = max(max_val, grid[x][y]);
    }

    int current_val = grid[ni][nj];

    // If the target neighbor is already the maximum and unique, no cost
    if (current_val == max_val) {
        // Check if it's unique maximum
        int count_max = 0;
        for (auto [x, y] : neighbors) {
            if (grid[x][y] == max_val) count_max++;
        }
        return (count_max == 1) ? 0 : 1;
    }

    // If target neighbor is not maximum, we need to make it maximum
    return max_val - current_val + 1;
}

int main() {
    cin >> N >> M;
    grid.resize(N, vector<int>(M));
    blocked.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int sx, sy, dx, dy;
    cin >> sx >> sy;
    sx--; sy--;
    cin >> dx >> dy;
    dx--; dy--;

    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int bi, bj;
        cin >> bi >> bj;
        bi--; bj--;
        blocked[bi][bj] = true;
    }

    vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
    priority_queue<tuple<int, int, int>,
                   vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>> pq;

    dist[sx][sy] = 0;
    pq.push({0, sx, sy});

    while (!pq.empty()) {
        auto [cost, i, j] = pq.top();
        pq.pop();

        if (cost != dist[i][j]) continue;
        if (i == dx && j == dy) {
            cout << cost << endl;
            return 0;
        }

        auto neighbors = get_neighbors(i, j);
        for (auto [ni, nj] : neighbors) {
            int c = compute_cost(i, j, ni, nj);
            if (c == INT_MAX) continue;

            if (dist[i][j] + c < dist[ni][nj]) {
                dist[ni][nj] = dist[i][j] + c;
                pq.push({dist[ni][nj], ni, nj});
            }
        }
    }

    cout << dist[dx][dy] << endl;
    return 0;
}
