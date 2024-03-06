#include <bits/stdc++.h>
using namespace std;
/*
*Time Complexity: O(N*W)
Reason: There are N*W states therefore at max ‘N*W’ new problems will be solved.
Space Complexity: O(N*W) + O(N)
*Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).
*/
// Recusion + memoization code
int solve(int idx, int w, vector<int>wt, vector<int>val, vector<vector<int>> &dp)
{
    //* base case ->> kabhi bhi ak element lejar socho 
    if (idx == 0)
    {
        if (w >= wt[idx])
        {
            return val[idx];
        }
        // yani w bag weight se jayada wt wala value idx zero per hi then return 0
        return 0;
    }
    if (dp[idx][w] != -1)
    {
        return dp[idx][w];
    }
    // we have two choicr at every idx pick and not pick
    int notPick = 0 + solve(idx - 1, w, wt, val, dp);
    int pick = 0;
    if (w >= wt[idx])
    {
        pick = val[idx] + solve(idx - 1, w - wt[idx], wt, val, dp);
    }
    return dp[idx][w] = max(pick, notPick);
}
// Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, vector<int>wt, vector<int>val, int n)
{
    // create 2d array becuse idx and  wt are changing
    // idx change hoga ->> 0->>n-1 isiliye n size ka liya hi
    // per wt 0 se W tak hoga isiliya ham col ka size W+1 liya hi
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return solve(n - 1, W, wt, val, dp);
}

int main()
{
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    int n = wt.size();

    cout << "The Maximum value of items the thief can steal is " << knapSack(W, wt, val, n);

    return 0;
}
