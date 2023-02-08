#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> result;
    int n = matrix.size();
    int top = 0;
    int right = n - 1;
    int bottom = n - 1;
    int left = 0;
    int index = 1;
    while (top <= bottom && left <= right)
    {
        // first row
        for (int j = left; j <= right; j++)
        {
            result.push_back(matrix[top][j]);
        }
        top++;
        // last column
        for (int i = top; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;
        // last row
        for (int j = right; j >= left; j--)
        {
            result.push_back(matrix[bottom][j]);
        }
        bottom--;
        // first column
        for (int i = bottom; i >= top; i--)
        {
            result.push_back(matrix[i][left]);
        }
        left++;
    }
    return result;
}

int main()
{
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = spiralOrder(v);
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    return 0;
}
