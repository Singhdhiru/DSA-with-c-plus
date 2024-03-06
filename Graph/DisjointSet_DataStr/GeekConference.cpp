#include <bits/stdc++.h>
using namespace std;
/*
 * Gfg   : https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-144/problems
 */
class DSU
{
public:
    vector<int> rank, size, parent;
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findPar(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int par_u = findPar(u);
        int par_v = findPar(v);
        if (par_u == par_v)
            return;
        int rank_u = rank[par_u];
        int rank_v = rank[par_v];
        if (rank_v == rank_u)
        {
            rank[par_u]++;
            parent[par_v] = par_u;
        }
        else if (rank_u > rank_v)
        {
            parent[par_v] = par_u;
        }
        else
        {
            parent[par_u] = par_v;
        }
    }

    void unionBySize(int u, int v)
    {
        int par_u = findPar(u);
        int par_v = findPar(v);

        if (par_u == par_v)
            return;

        int size_u = size[par_u];
        int size_v = size[par_v];

        if (size_v > size_u)
        {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
        else
        {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
    }
};
class Solution
{
public:
    vector<int> maximumFriends(int N, vector<vector<int>> &arr)
    {
        DSU ds(N + 16);
        int mx = 0;
        vector<int> ans;
        for (auto &e : arr)
        {
            int u = e[0], v = e[1];

            int parU = ds.findPar(u), parV = ds.findPar(v);
            // dono ka parent jab same ho toh
            if (parU == parV)
            {
                mx = max(mx, ds.size[parU] - 1);
            }
            // dono ka parent ka same na ho toh add bhi karna padega
            else
            {
                //? do alag alag component hi
                mx = max(mx, ds.size[parU] + ds.size[parV] - 1); //* diff component ko add karenge toh uska size add kr ke -1 kar dunga
                ds.unionBySize(u, v);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>>arr = {{1,2}, {3,4}, {1,3}, {2,4}};
    int n = arr.size();
    Solution obj;
    vector<int> ans = obj.maximumFriends(n, arr);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}