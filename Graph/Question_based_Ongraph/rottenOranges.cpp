#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int vis[n][m];
    int minTime = 0;

    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
            else {
                vis[i][j] = 0;
            }
        }
    }

    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};

    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();

        minTime = max(minTime, t);

        for (int i = 0; i < 4; i++) {
            int nrow = r + row[i];
            int ncol = c + col[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 0 && grid[i][j] == 1) {
                return -1;
            }
        }
    }

    return minTime;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << orangesRotting(grid); // Output: 4

    return 0;
}
