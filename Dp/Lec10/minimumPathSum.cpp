
#include <bits/stdc++.h>
using namespace std;

// recursion code-> tle
int solve(int i, int j, vector<vector<int>> &grid)
{
    // base case
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }
    if (i < 0 || j < 0)
    {
        return 1e9;
    }
    // if(dp[i][j] != -1){
    //     return dp[i][j];
    // }
    int up = grid[i][j] + solve(i - 1, j, grid);
    int left = grid[i][j] + solve(i, j - 1, grid);
    return min(up, left);
}

// memoization code

int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // Base cases
    if (i == 0 && j == 0)
        return matrix[0][0]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
    if (i < 0 || j < 0)
        return 1e9; // If we go out of bounds, return a large value to avoid considering this path
    if (dp[i][j] != -1)
        return dp[i][j]; // If the result is already computed, return it

    // Calculate the minimum sum path by considering moving up and moving left
    int up = matrix[i][j] + minSumPathUtil(i - 1, j, matrix, dp);
    int left = matrix[i][j] + minSumPathUtil(i, j - 1, matrix, dp);

    // Store the result in the DP table and return it
    return dp[i][j] = min(up, left);
}

// Main function to find the minimum sum path in the matrix
int minSumPath(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));   // DP table to memoize results
    return minSumPathUtil(n - 1, m - 1, matrix, dp); // Start from the bottom-right corner
}

int main()
{
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}};

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Minimum sum path: " << minSumPath(n, m, matrix) << endl;
    return 0;
}
