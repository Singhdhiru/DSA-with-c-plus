#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> visted, vector<vector<int>> &m)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visted[x][y] == 0 && m[x][y] == 1)
    {

        return true;
    }
    else
    {
        return false;
    }
}
void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visted, string path)
{
    // you are reached x and y
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    // source ko visted main 1 mark kar diya
    visted[x][y] = 1;
    //  you have four choice ->> 'D','L', 'R' 'U'

    // choice 1st->>"D"
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, n, visted, m))
    {
        path.push_back('D');
        // recursive call
        solve(m, n, ans, newx, newy, visted, path);
        path.pop_back();
    }
    // *choive 2nd ->> "l"
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, n, visted, m))
    {
        path.push_back('L');
        // *recursive call
        solve(m, n, ans, newx, newy, visted, path);
        path.pop_back();
    }
    // *choice 3rd->>"R"
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, n, visted, m))
    {
        path.push_back('R');
        // recursive call
        solve(m, n, ans, newx, newy, visted, path);
        path.pop_back();
    }
    //* choice 4th->> "U"
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, n, visted, m))
    {
        path.push_back('U');
        // recursive call
        solve(m, n, ans, newx, newy, visted, path);
        path.pop_back();
    }

    visted[x][y] = 0;
}
int main()
{
    int n = 4;
    vector<vector<int>> m = {{1 , 0, 0, 0},{1, 1, 0, 1}, {1, 1, 0, 0},{0, 1, 1, 1}};
    vector<string> ans;
    if (m[0][0] == 0)
    { //* pahla hi 0 ho toh anly ans return kar denge
        cout<<"not possible to go destination"<<endl;
    }
    int srcx = 0;
    int srcy = 0;
    //* visted vector bna kar zero se mark kar diya
    vector<vector<int>> visted = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visted[i][j] = 0;
        }
    }
    //* isme path ko store kar leneg
    string path = "";

    //* function call
    solve(m, n, ans, srcx, srcy, visted, path);
    // *sort answer in lexographical order
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    // return ans;
}
