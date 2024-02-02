
#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum path sum in the given matrix
int getMaxPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size(); // Number of rows in the matrix
    int m = matrix[0].size(); // Number of columns in the matrix

    vector<int> prev(m, 0); // Represents the previous row's maximum path sums
    vector<int> cur(m, 0);  // Represents the current row's maximum path sums

    // Initialize the first row (base condition)
    for (int j = 0; j < m; j++) {
        prev[j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Calculate the maximum path sum for the current cell considering three possible directions: up, left diagonal, and right diagonal

            // Up direction
            int up = matrix[i][j] + prev[j];

            // Left diagonal direction (if it's a valid move)
            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0) {
                leftDiagonal += prev[j - 1];
            } else {
                leftDiagonal += -1e9; // A very large negative value to represent an invalid path
            }

            // Right diagonal direction (if it's a valid move)
            int rightDiagonal = matrix[i][j];
            if (j + 1 < m) {
                rightDiagonal += prev[j + 1];
            } else {
                rightDiagonal += -1e9; // A very large negative value to represent an invalid path
            }

            // Store the maximum of the three paths in the current row
            cur[j] = max(up, max(leftDiagonal, rightDiagonal));
        }

        // Update the 'prev' array with the values from the 'cur' array for the next iteration
        prev = cur;
    }

    // Find the maximum value in the last row of 'prev', which represents the maximum path sums ending at each cell
    int maxi = INT_MIN;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, prev[j]);
    }

    // The maximum path sum is the maximum value in the last row of 'prev'
    return maxi;
}

int main() {
    // Define the matrix as a 2D vector
    vector<vector<int>> matrix{{1, 2, 10, 4},
                                {100, 3, 2, 1},
                                {1, 1, 20, 2},
                                {1, 2, 2, 1}};

    // Call the getMaxPathSum function and print the result
    cout << getMaxPathSum(matrix);

    return 0;
}
