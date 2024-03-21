#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// *https://www.geeksforgeeks.org/problems/rod-cutting0840/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

int solve(int idx, int N, vector<int> &price, vector<vector<int>> &dp)
{
    // base case
    if (idx == 0)
    {
        // idx zero jo bhi length bacha hi rod ka use price se multiply kr ke bej do simple hi
        return N * price[0];
    }
    if (dp[idx][N] != -1)
    {
        return dp[idx][N];
    }
    int notTake = 0 + solve(idx - 1, N, price, dp);
    int take = INT_MIN;
    int lenght = idx + 1; // idx 0 se begin hi aur lehgt 1 se kisi bhi point per rod ka lenght idx+1 hoga
    if (lenght <= N)
    {
        take = price[idx] + solve(idx, N - lenght, price, dp);
    }
    return dp[idx][N] = max(notTake, take);
}
int cutRod(vector<int> &price, int n)
{
    // first jo n o idx hi aur second n rod size hi
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(n - 1, n, price, dp);
}

int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int N = price.size();
    cout << "Maximum obtainable value is " << cutRod(price, N) << endl;
    return 0;
}
