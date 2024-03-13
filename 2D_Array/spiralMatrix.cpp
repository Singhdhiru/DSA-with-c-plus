#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    MY YOUTUBE VIDEO FOR THIS Qn : https://www.youtube.com/watch?v=73j2ipxR958
    Company Tags                 : Paytm, Zoho, Morgan Stanley, Accolite, Amazon, Microsoft, Snapdeal,D-E-Shaw, MakeMyTrip, Oracle, MAQ Software, nearbuy, Nagarro, BrowserStack

    Frequency                    : 80%
    Leetcode Qn Link             : https://leetcode.com/problems/spiral-matrix/
    Similar GfG Link             : https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
*/

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    if (matrix.size() == 0)
        return {};
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> result;
    int top = 0;
    int down = m - 1;
    int left = 0;
    int right = n - 1;
    // we have four directions
    int dir = 0;
    // dir
    // 0   -> left  to right
    // 1   -> top   to down
    // 2   -> right to left
    // 3   -> down  to top

    while (top <= down && left <= right)
    {
        // left to right
        if (dir == 0)
        {
            for (int i = left; i <= right; i++)
            {
                result.push_back(matrix[top][i]);
            }
            top++;
        }

        // top to down
        if (dir == 1)
        {
            for (int i = top; i <= down; i++)
            {
                result.push_back(matrix[i][right]);
            }
            right--;
        }

        // right to left
        if (dir == 2)
        {
            for (int i = right; i >= left; i--)
            {
                result.push_back(matrix[down][i]);
            }
            down--;
        }

        // down to top
        if (dir == 3)
        {
            for (int i = down; i >= top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        dir++;
        // jab direction equal to 4 ho jaye tab phir se zero kar do yani 1 chakkar ho gaya
        if(dir == 4){
            dir = 0;
        }
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
