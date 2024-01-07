
#include <bits/stdc++.h>
using namespace std;

// Recursive function to count the number of ways to reach (i, j) from (0, 0)
// in a grid of size m x n
int countWaysUtil(int i, int j, vector<vector<int>> &dp)
{
    // Base case: If we reach the top-left corner (0, 0), there is one way.
    if (i == 0 && j == 0)
        return 1;

    // If we go out of bounds or reach a blocked cell, there are no ways.
    if (i < 0 || j < 0)
        return 0;

    // If we have already computed the number of ways for this cell, return it.
    if (dp[i][j] != -1)
        return dp[i][j];

    // Calculate the number of ways by moving up and left recursively.
    int up = countWaysUtil(i - 1, j, dp);
    int left = countWaysUtil(i, j - 1, dp);

    // Store the result in the dp table and return it.
    return dp[i][j] = up + left;
}

// Function to count the number of ways to reach the bottom-right cell (m-1, n-1)
// from the top-left cell (0, 0) in a grid of size m x n
int countWays(int m, int n)
{
    // Create a memoization table (dp) to store the results of subproblems.
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // Call the utility function with the bottom-right cell as the starting point.
    return countWaysUtil(m - 1, n - 1, dp);
}

int main()
{
    int m = 3;
    int n = 2;

    // Call the countWays function and print the result.
    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n) << endl;

    return 0;
}
