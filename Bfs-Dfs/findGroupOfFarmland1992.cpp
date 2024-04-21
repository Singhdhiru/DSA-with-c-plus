#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3ZaQTCH83fY
    Company Tags                : Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/find-all-groups-of-farmland/
*/
// Approach-1 (Using DFS)
// T.C : O(m*n)
// S.C : O(1) AUxiliary space and O(m*n) system stack space because of recursion
class Solution
{
public:
    int m;
    int n;
    vector<vector<int>> result;

    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<int>> &land, int i, int j, int &r2, int &c2)
    {
        land[i][j] = 0;

        r2 = max(r2, i);
        c2 = max(c2, j);

        for (auto &dir : directions)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && land[i_][j_] == 1)
            {
                dfs(land, i_, j_, r2, c2);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        m = land.size();
        n = land[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (land[i][j] == 1)
                {
                    int r1 = i;
                    int c1 = j;
                    int r2 = -1;
                    int c2 = -1;

                    dfs(land, i, j, r2, c2);
                    result.push_back({r1, c1, r2, c2});
                }
            }
        }

        return result;
    }
};
// Approach-2 (Using BFS)
// T.C : O(m*n)
// S.C : O(m*n)
class solution
{
public:
    int n;
    int m;
    vector<vector<int>> result;
    vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void bfs(vector<vector<int>> &land, int i, int j, int &r2, int &c2)
    {
        queue<pair<int, int>> que;
        que.push({i, j});
        while (!que.empty())
        {
            pair<int, int> p = que.front();
            que.pop();
            r2 = max(r2, p.first);
            c2 = max(c2, p.second);

            for (auto &dir : directions)
            {
                int i_ = p.first + dir[0];
                int j_ = p.second + dir[1];
                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && land[i_][j_] == 1)
                {
                    land[i_][j_] = 0; // visted kr do
                    que.push({i_, j_});
                }
            }
        }
    }
    vector<vector<int>> findFarmLand(vector<vector<int>> land)
    {
        n = land.size();
        m = land[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (land[i][j] == 1)
                {
                    int r1 = i;
                    int c1 = j;
                    int r2 = -1;
                    int c2 = -1;
                    bfs(land, i, j, r2, c2);
                    result.push_back({r1, c1, r2, c2});
                }
            }
        }
        return result;
    }
};
int main()
{
    // Using BFS
    solution sol;
    vector<vector<int>> land = {{1, 0, 0}, {0, 1, 1}, {0, 1, 1}};
    vector<vector<int>> result = sol.findFarmLand(land);

    cout << "Farmlands: \n";
    for (auto &land : result)
    {
        cout << "[";
        for (int i = 0; i < 4; ++i)
        {
            cout << land[i];
            if (i != 3)
                cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
