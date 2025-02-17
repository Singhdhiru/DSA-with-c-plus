#include <bits/stdc++.h>

using namespace std;

bool isSafe(int newX, int newY, vector<vector<int>> &vis,
            vector<vector<int>> &arr, int n)
{
    if ((newX >= 0 && newX < n) && (newY >= 0 && newY < n) &&
        vis[newX][newY] != 1 && arr[newX][newY] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans,
            vector<vector<int>> &visited, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // Down
    if (isSafe(x + 1, y, visited, arr, n))
    {
        visited[x][y] = 1;
        solve(x + 1, y, arr, n, ans, visited, path + 'D');
        visited[x][y] = 0;
    }
    // Left
    if (isSafe(x, y - 1, visited, arr, n))
    {
        visited[x][y] = 1;
        solve(x, y - 1, arr, n, ans, visited, path + 'L');
        visited[x][y] = 0;
    }
    // Right
    if (isSafe(x, y + 1, visited, arr, n))
    {
        visited[x][y] = 1;
        solve(x, y + 1, arr, n, ans, visited, path + 'R');
        visited[x][y] = 0;
    }
    // Up
    if (isSafe(x - 1, y, visited, arr, n))
    {
        visited[x][y] = 1;
        solve(x - 1, y, arr, n, ans, visited, path + 'U');
        visited[x][y] = 0;
    }
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    if (arr[0][0] == 0)
    {
        return ans;
    }
    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";
    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the maze: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    cout << "Enter the maze elements (0 for blocked and 1 for open paths):\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }

    vector<string> ans = searchMaze(arr, n);

    if (ans.empty())
    {
        cout << "No paths found from (0, 0) to (" << n - 1 << ", " << n - 1 << ")." << endl;
    }
    else
    {
        cout << "Paths from (0, 0) to (" << n - 1 << ", " << n - 1 << "):\n";
        for (const string &path : ans)
        {
            cout << path << endl;
        }
    }

    return 0;
}
