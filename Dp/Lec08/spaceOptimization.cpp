
#include <bits/stdc++.h>
using namespace std;

// Function to count the number of ways to reach the bottom-right cell (m-1, n-1)
// from the top-left cell (0, 0) in a grid of size m x n
int countWays(int m, int n)
{
    // Create a vector to represent the previous row of the grid.
    vector<int> prev(n, 0);

    // Iterate through the rows of the grid.
    for (int i = 0; i < m; i++)
    {
        // Create a temporary vector to represent the current row.
        vector<int> temp(n, 0);

        // Iterate through the columns of the grid.
        for (int j = 0; j < n; j++)
        {
            // Base case: If we are at the top-left cell (0, 0), there is one way.
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }

            // Initialize variables to store the number of ways from the cell above (up) and left (left).
            int up = 0;
            int left = 0;

            // If we are not at the first row (i > 0), update 'up' with the value from the previous row.
            if (i > 0)
                up = prev[j];

            // If we are not at the first column (j > 0), update 'left' with the value from the current row.
            if (j > 0)
                left = temp[j - 1];

            // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.
            temp[j] = up + left;
        }

        // Update the previous row with the values calculated for the current row.
        prev = temp;
    }

    // The result is stored in the last cell of the previous row (n-1).
    return prev[n - 1];
}

int main()
{
    int m = 3;
    int n = 2;

    // Call the countWays function and print the result.
    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n) << endl;

    return 0;
}
