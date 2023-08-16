#include <bits/stdc++.h> 
using namespace std;

bool isSafe(int row, int col, vector<vector<int>>& board, int val) {
    for (int i = 0; i < 9; i++) {
        // check row
        if (board[row][i] == val) {
            return false;
        }
        // check column
        if (board[i][col] == val) {
            return false;
        }
        // check 3x3 matrix
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& sudoku) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                // Empty Cell
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(i, j, sudoku, val)) {
                        sudoku[i][j] = val;
                        // next solution possible
                        if (solve(sudoku)) {
                            return true;
                        } else {
                            // backtrack
                            sudoku[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku) {
    solve(sudoku);
}

int main() {
    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    solveSudoku(sudoku);
    
    // Print the solved Sudoku
    for (const auto& row : sudoku) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
