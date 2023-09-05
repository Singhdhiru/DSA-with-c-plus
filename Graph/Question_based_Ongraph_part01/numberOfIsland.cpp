#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            int curRow = current.first;
            int curCol = current.second;

            for (int delrow = -1; delrow <= 1; delrow++) {
                for (int delcol = -1; delcol <= 1; delcol++) {
                    int newRow = curRow + delrow;
                    int newCol = curCol + delcol;

                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m
                        && !vis[newRow][newCol] && grid[newRow][newCol] == '1') {
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return cnt;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution sol;
    int islandCount = sol.numIslands(grid);
    cout << "Number of islands: " << islandCount << endl;

    return 0;
}
