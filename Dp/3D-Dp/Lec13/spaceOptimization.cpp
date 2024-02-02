
#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(N*M*M)*9

Reason: The outer nested loops run for (N*M*M) times and the inner two nested loops run for 9 times.

Space Complexity: O(M*M)

Reason: We are using an external array of size ‘M*M’.
*/
// Function to find the maximum chocolates that can be collected
int maximumChocolates(int n, int m, vector<vector<int>> &grid)
{
    // Create two 2D vectors 'front' and 'cur' to store computed results
    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> cur(m, vector<int>(m, 0));

    // Initialize 'front' for the last row
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    // Outer nested loops for traversing the DP array from the second-to-last row up to the first row
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = INT_MIN;

                // Inner nested loops to try out 9 options (diagonal moves)
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        int ans;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        // Check if the move is valid (within the grid boundaries)
                        if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                            ans += -1e9; // A very large negative value to represent an invalid move
                        else
                            ans += front[j1 + di][j2 + dj]; // Include the value from the 'front' array

                        maxi = max(ans, maxi); // Update the maximum result
                    }
                }
                cur[j1][j2] = maxi; // Store the maximum result for this state in the 'cur' array
            }
        }
        front = cur; // Update 'front' with the values from 'cur' for the next iteration
    }

    // The maximum chocolates that can be collected is stored at the top-left corner of the 'front' array
    return front[0][m - 1];
}

int main()
{
    // Define the grid as a 2D vector
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int n = matrix.size();    // Number of rows
    int m = matrix[0].size(); // Number of columns

    // Call the maximumChocolates function and print the result
    cout << maximumChocolates(n, m, matrix);

    return 0;
}
