#include <iostream>
#include <vector>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=lzAOWVGkmfs
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/count-unguarded-cells-in-the-grid
*/
//* Approach-1 (Simple Simulation)
// T.C : O(m*n + G*(m+n)), where G = size of guards
// S.C : O(m*n), considering the size of grid we took
class Solution
{
public:
    void markGuarded(int row, int col, vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Up Direction
        for (int i = row - 1; i >= 0; i--)
        {
            if (grid[i][col] == 2 || grid[i][col] == 3)
            {
                break;
            }
            grid[i][col] = 1;
        }

        // Down Direction
        for (int i = row + 1; i < m; i++)
        {
            if (grid[i][col] == 2 || grid[i][col] == 3)
            {
                break;
            }
            grid[i][col] = 1;
        }

        // Left Direction
        for (int j = col - 1; j >= 0; j--)
        {
            if (grid[row][j] == 2 || grid[row][j] == 3)
            {
                break;
            }
            grid[row][j] = 1;
        }

        // Right Direction
        for (int j = col + 1; j < n; j++)
        {
            if (grid[row][j] == 2 || grid[row][j] == 3)
            {
                break;
            }
            grid[row][j] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Mark guards on the grid
        for (vector<int> &guard : guards)
        {
            int i = guard[0];
            int j = guard[1];
            grid[i][j] = 2;
        }

        // Mark walls on the grid
        for (vector<int> &wall : walls)
        {
            int i = wall[0];
            int j = wall[1];
            grid[i][j] = 3;
        }

        // Mark cells guarded by guards
        for (vector<int> &guard : guards)
        {
            int i = guard[0];
            int j = guard[1];
            markGuarded(i, j, grid);
        }

        // Count unguarded cells
        int unguardedCells = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    unguardedCells++;
                }
            }
        }
        return unguardedCells;
    }
};
// Approach-2 (DFS)
// T.C : O(m*n + G*(m+n)), where G =  size of guards
// S.C : O(m*n), considering the size of grid we took
class SolutionDfs
{
public:
    void dfs(vector<vector<int>> &grid, int row, int col, int rows, int cols, int direction)
    {
        // Boundary check and skipping guarded or walled cells
        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 1 || grid[row][col] == 2)
        {
            return;
        }

        // Mark the current cell as visited by a guard's line of sight
        grid[row][col] = 3;

        // Continue the DFS in the specified direction
        if (direction == 1)
        { // UP
            dfs(grid, row - 1, col, rows, cols, direction);
        }
        else if (direction == 2)
        { // DOWN
            dfs(grid, row + 1, col, rows, cols, direction);
        }
        else if (direction == 3)
        { // LEFT
            dfs(grid, row, col - 1, rows, cols, direction);
        }
        else
        { // RIGHT
            dfs(grid, row, col + 1, rows, cols, direction);
        }
    }

    int countUnguardedDfs(int rows, int cols, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        // Initialize the grid
        vector<vector<int>> grid(rows, vector<int>(cols, 0));

        // Mark guard positions
        for (const auto &guard : guards)
        {
            int i = guard[0];
            int j = guard[1];
            grid[i][j] = 1; // Guard cell
        }

        // Mark wall positions
        for (const auto &wall : walls)
        {
            int i = wall[0];
            int j = wall[1];
            grid[i][j] = 2; // Wall cell
        }

        // Perform DFS for each guard in all four directions (UP, DOWN, LEFT, RIGHT)
        for (const auto &guard : guards)
        {
            int guardRow = guard[0];
            int guardCol = guard[1];

            dfs(grid, guardRow - 1, guardCol, rows, cols, 1); // UP
            dfs(grid, guardRow + 1, guardCol, rows, cols, 2); // DOWN
            dfs(grid, guardRow, guardCol - 1, rows, cols, 3); // LEFT
            dfs(grid, guardRow, guardCol + 1, rows, cols, 4); // RIGHT
        }

        // Count unguarded cells
        int unguardedCount = 0;
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                if (grid[row][col] == 0)
                {
                    ++unguardedCount;
                }
            }
        }

        return unguardedCount;
    }
};
// Main function to test the Solution class
int main()
{
    Solution solution;

    // Example input
    int m = 5; // Number of rows
    int n = 5; // Number of columns

    vector<vector<int>> guards = {{0, 0}, {1, 1}, {4, 4}}; // Guards' positions
    vector<vector<int>> walls = {{1, 0}, {2, 2}, {3, 3}};  // Walls' positions

    int result = solution.countUnguarded(m, n, guards, walls);
    cout << "Number of unguarded cells: " << result << endl;

    cout << "Using Dfs ->> ";
    SolutionDfs solutionDfs;
    int result1 = solutionDfs.countUnguardedDfs(m, n, guards, walls);
    cout << "Number of unguarded cells: " << result1 << endl;

    return 0;
}