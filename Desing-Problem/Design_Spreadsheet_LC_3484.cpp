#include <bits/stdc++.h>
using namespace std;
class Spreadsheet
{
public:
    vector<vector<int>> spreadS;
    Spreadsheet(int rows)
    {
        spreadS = vector<vector<int>>(26, vector<int>(rows + 1, 0));
    }

    void setCell(string cell, int value)
    {
        int row = cell[0] - 'A';
        int col = 0;
        for (int i = 1; i < cell.size(); i++)
        {
            col = col * 10;
            col += cell[i] - '0';
        }
        spreadS[row][col] = value;
    }

    void resetCell(string cell)
    {
        int row = cell[0] - 'A';
        int col = 0;
        for (int i = 1; i < cell.size(); i++)
        {
            col = col * 10;
            col += cell[i] - '0';
        }
        spreadS[row][col] = 0;
    }

    int getValue(string formula)
    {
        int ans = 0;
        int i = 1; // Skip the '=' character

        // Case 1: First operand is a cell reference (starts with a letter)
        if (formula[i] > '9')
        {
            int row = formula[i] - 'A';
            i++;
            int col = 0;
            // Parse column number until we reach the '+' operator
            for (; formula[i] != '+'; i++)
            {
                col *= 10;
                col += formula[i] - '0';
            }
            // Add the value of the first cell
            ans += spreadS[row][col];
            i++; // Skip the '+' operator

            // Parse second operand
            if (formula[i] > '9')
            { // Second operand is a cell reference
                row = formula[i] - 'A';
                i++;
                col = 0;
                for (; i < formula.size(); i++)
                {
                    col *= 10;
                    col += formula[i] - '0';
                }
                ans += spreadS[row][col];
            }
            else
            { // Second operand is a number
                col = 0;
                for (; i < formula.size(); i++)
                {
                    col *= 10;
                    col += formula[i] - '0';
                }
                ans += col;
            }
        }
        // Case 2: First operand is a number
        else
        {
            int col = 0;
            int row;
            // Parse the first number until we reach the '+' operator
            for (; formula[i] != '+'; i++)
            {
                col *= 10;
                col += formula[i] - '0';
            }
            ans += col;
            i++; // Skip the '+' operator

            // Parse second operand
            if (formula[i] > '9')
            { // Second operand is a cell reference
                row = formula[i] - 'A';
                i++;
                col = 0;
                for (; i < formula.size(); i++)
                {
                    col *= 10;
                    col += formula[i] - '0';
                }
                ans += spreadS[row][col];
            }
            else
            { // Second operand is a number
                col = 0;
                for (; i < formula.size(); i++)
                {
                    col *= 10;
                    col += formula[i] - '0';
                }
                ans += col;
            }
        }
        return ans;
    }
};

int main()
{
    // Create a spreadsheet with 10 rows
    Spreadsheet spreadsheet(10);

    // Set some cell values
    spreadsheet.setCell("A1", 5);
    spreadsheet.setCell("B2", 10);
    spreadsheet.setCell("C3", 15);

    // Print some cell values
    cout << "A1 = " << spreadsheet.spreadS[0][1] << endl;
    cout << "B2 = " << spreadsheet.spreadS[1][2] << endl;
    cout << "C3 = " << spreadsheet.spreadS[2][3] << endl;

    // Test formulas
    cout << "=A1+B2 = " << spreadsheet.getValue("=A1+B2") << endl; // Should be 15
    cout << "=5+C3 = " << spreadsheet.getValue("=5+C3") << endl;   // Should be 20
    cout << "=B2+10 = " << spreadsheet.getValue("=B2+10") << endl; // Should be 20

    // Reset a cell and test again
    spreadsheet.resetCell("A1");
    cout << "After reset, A1 = " << spreadsheet.spreadS[0][1] << endl;
    cout << "=A1+B2 = " << spreadsheet.getValue("=A1+B2") << endl; // Should be 10 now

    return 0;
}