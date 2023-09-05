#include <iostream>
#include <vector>

using namespace std;

void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int delRow[], int delCol[],int iniColor)
{
    // color with new color
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    // there are exactly 4 neighbours
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        // check for valid coordinate
        // then check for same initial color and unvisited pixel
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
        {
            dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    // get initial color
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;
    // delta row and delta column for neighbours
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
    return ans;
}

int main()
{
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    cout << "Original Image:" << endl;
    for (const auto &row : image)
    {
        for (int pixel : row)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }

    cout << "Flood Filled Image:" << endl;
    for (const auto &row : result)
    {
        for (int pixel : row)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
