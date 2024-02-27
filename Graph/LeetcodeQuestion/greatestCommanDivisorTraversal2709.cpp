#include <bits/stdc++.h>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=TI-xIXH4EnE
    Company Tags                : GOOGLE
    *Leetcode Link               : https://leetcode.com/problems/greatest-common-divisor-traversal/
*/
//*T.C : O(N * sqrt(N) * alpha) where alpha is for Union Find operations. But it's small , so we can ignore it to O(1) as average --> O(N*sqrt(N))
//*S.C : O(N)
class DisjointSet
{
    vector<int> parent, size;
    int maxComponent;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        // shru mai mai n component hoga yani number of node
        maxComponent = n;
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        // connect karenge toh maxComponent decrese hoga 1 se
        maxComponent -= 1;
    }
    int countmaxComponent()
    {
        return maxComponent;
    }
};

class Solution
{
public:
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = nums.size();
        DisjointSet dsu(n);

        int m = *max_element(nums.begin(), nums.end());

        vector<int> first(m + 1, -1);

        for (int i = 0; i < n; ++i)
        {

            for (int prime = 2; prime * prime <= nums[i]; ++prime)
            {
                if (nums[i] % prime != 0)
                    continue;

                if (first[prime] != -1)
                    dsu.unionBySize(first[prime], i);
                else
                    first[prime] = i;

                while (nums[i] % prime == 0)
                    nums[i] /= prime;
            }
            // ye lilha gaya 2 aur 3 value ke liye
            if (nums[i] > 1)
            {
                if (first[nums[i]] != -1)
                    dsu.unionBySize(first[nums[i]], i);
                else
                    first[nums[i]] = i;
            }
        }

        return dsu.countmaxComponent() == 1;
    }
};

int main()
{
    vector<int> vec = {2, 3, 6};
    Solution *obj;
    cout << "kya ham her vec ke element per ja sakte hi-> " << obj->canTraverseAllPairs(vec) << endl;
    return 0;
}