#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid,
             vector<pair<int, int>> &vec, int baserow, int basecol)
    {
        vis[row][col] = 1;
        vec.push_back({row - baserow, col - basecol});
        int m = grid.size();
        int n = grid[0].size();
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, vis, grid, vec, baserow, basecol);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        set<vector<pair<int, int>>> st;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, vis, grid, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Example usage
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}};

    int result = solution.countDistinctIslands(grid);

    cout << "Number of distinct islands: " << result << endl;

    return 0;
}
