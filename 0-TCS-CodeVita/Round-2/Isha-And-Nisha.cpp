#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<char>> boardData;
string target;
int clueCount;

vector<int> stepLimit;
vector<vector<int>> clueBox;

vector<vector<bool>> used;
int maxSatisfied = 0;
bool everyClueSatisfied = false;
bool anyPathFound = false;

int dirX[4] = {0, 0, -1, 1};
int dirY[4] = {-1, 1, 0, 0};

void explore(int idx, int x, int y, vector<pair<int,int>> &route) {
    if (everyClueSatisfied) return;

    if (idx == target.size()) {
        anyPathFound = true;
        int satisfied = 0;

        for (int k = 0; k < clueCount; k++) {
            int limit = stepLimit[k];
            if (limit > route.size()) {
                satisfied++;
            } else {
                int check = limit - 1;
                int px = route[check].first;
                int py = route[check].second;

                int xl = clueBox[k][0];
                int yl = clueBox[k][1];
                int xr = clueBox[k][2];
                int yr = clueBox[k][3];

                if (!(px >= xl && px <= xr && py >= yl && py <= yr)) {
                    satisfied++;
                }
            }
        }

        if (satisfied > maxSatisfied) {
            maxSatisfied = satisfied;
            if (maxSatisfied == clueCount) {
                everyClueSatisfied = true;
            }
        }
        return;
    }

    for (int d = 0; d < 4; d++) {
        int nx = x + dirX[d];
        int ny = y + dirY[d];

        if (nx >= 0 && nx < R && ny >= 0 && ny < C &&
            !used[nx][ny] && boardData[nx][ny] == target[idx]) {

            used[nx][ny] = true;
            route.push_back({nx, ny});
            explore(idx + 1, nx, ny, route);
            route.pop_back();
            used[nx][ny] = false;

            if (everyClueSatisfied) return;
        }
    }
}

int main() {
    cin >> R >> C;
    boardData.assign(R, vector<char>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> boardData[i][j];
        }
    }

    cin >> clueCount;
    stepLimit.resize(clueCount);
    clueBox.assign(clueCount, vector<int>(4));

    for (int i = 0; i < clueCount; i++) {
        cin >> stepLimit[i];
        cin >> clueBox[i][0] >> clueBox[i][1] >> clueBox[i][2] >> clueBox[i][3];

        clueBox[i][0]--;
        clueBox[i][1]--;
        clueBox[i][2]--;
        clueBox[i][3]--;
    }

    cin >> target;

    if (target.empty()) {
        cout << "Impossible";
        return 0;
    }

    used.assign(R, vector<bool>(C, false));
    vector<pair<int,int>> route;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (boardData[i][j] == target[0]) {
                used[i][j] = true;
                route.push_back({i, j});
                explore(1, i, j, route);
                route.pop_back();
                used[i][j] = false;

                if (everyClueSatisfied) break;
            }
        }
        if (everyClueSatisfied) break;
    }

    if (!anyPathFound) {
        cout << "Impossible";
    } else {
        if (maxSatisfied == clueCount) {
            cout << "All clues are correct";
        } else {
            cout << clueCount - maxSatisfied;
        }
    }

    return 0;
}
