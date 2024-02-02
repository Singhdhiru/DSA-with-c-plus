
#include <bits/stdc++.h>
using namespace std;

// Helper function to count the number of paths from (i, j) to (0, 0)
int mazeObstaclesUtil(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp)
{
    // Base cases
    if (i > 0 && j > 0 && maze[i][j] == -1)
        return 0; // If there's an obstacle at (i, j), return 0
    if (i == 0 && j == 0)
        return 1; // If we reach the destination (0, 0), return 1
    if (i < 0 || j < 0)
        return 0; // If we go out of bounds, return 0
    if (dp[i][j] != -1)
        return dp[i][j]; // If the result is already computed, return it

    // Recursive calls to explore paths from (i, j) to (0, 0)
    int up = mazeObstaclesUtil(i - 1, j, maze, dp);
    int left = mazeObstaclesUtil(i, j - 1, maze, dp);

    // Store the result in the DP table and return it
    return dp[i][j] = up + left;
}

// Main function to count paths with obstacles in a maze
int mazeObstacles(int n, int m, vector<vector<int>> &maze)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));    // DP table to memoize results
    return mazeObstaclesUtil(n - 1, m - 1, maze, dp); // Start from the bottom-right corner
}

int main()
{
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}};

    int n = maze.size();
    int m = maze[0].size();

    cout << "Number of paths with obstacles: " << mazeObstacles(n, m, maze) << endl;
    return 0;
}
