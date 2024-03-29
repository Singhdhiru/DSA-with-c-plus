
#include <bits/stdc++.h>
using namespace std;

// Recursion code
// time complexity->> exponential
// space complexity->> O(n*n)->recursion call stack
int solve(int i, int j, int n, vector<vector<int>> &triangle){
    // ? base case
    if(i == n-1){
        return triangle[i][j];
    }
    int down = triangle[i][j]+solve(i+1, j, n,triangle);
    int diagonal = triangle[i][j]+solve(i+1, j+1, n, triangle);
    return min(down,diagonal);
}


// Memoization code->> 
/*
Complexity Analysis
Time Complexity: O(N*N)

Reason: There are two nested loops

Space Complexity: O(N*N)

Reason: We are using an external array of size ‘N*N’. The stack space will be eliminated.
*/
// Function to find the minimum path sum recursively with memoization
int minimumPathSumUtil(int i, int j, vector<vector<int>> &triangle, int n,vector<vector<int>> &dp)
{
    // If the result for this cell is already calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    // If we're at the bottom row, return the value of the current cell
    if (i == n - 1)
        return triangle[i][j];

    // Calculate the sum of two possible paths: going down and going diagonally
    int down = triangle[i][j] + minimumPathSumUtil(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + minimumPathSumUtil(i + 1, j + 1, triangle, n, dp);

    // Store the minimum of the two paths in the dp table and return it
    return dp[i][j] = min(down, diagonal);
}

// Function to find the minimum path sum in the given triangle
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Create a memoization table to store computed results
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // Call the recursive function to find the minimum path sum
    return minimumPathSumUtil(0, 0, triangle, n, dp);

    // ? recursion function call
    // return solve(0, 0,n,triangle);
}

int main()
{
    // Define the triangle as a 2D vector
    vector<vector<int>> triangle{{1},{2, 3},{3, 6, 7},{8, 9, 6, 10}};

    // Get the number of rows in the triangle
    int n = triangle.size();

    // Call the minimumPathSum function and print the result
    cout << minimumPathSum(triangle, n);

    return 0;
}
