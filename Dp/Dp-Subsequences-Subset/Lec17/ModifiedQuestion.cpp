// ? 0 <= 'arr[i]' <= 1000
// * testcase ->> arr->{0,0,1} and target = 1
// ! o/p ->> 4 hona chayiye per pahle wale code ke dawara 1 anser aayega
#include <bits/stdc++.h>
using namespace std;
// * recursion + Memoization
int mod = 1000000007;
int solve(int idx, vector<vector<int>> &dp, vector<int> &arr, int sum)
{
    // ! modified base case karna hi
    if (idx == 0)
    {
        // * sum ==0 aur arr[0] toh hamare upper hi le bhi sakte hi aur nahi bhi we have 2 choice le sakte aur nahi bhi ->> return 2
        if (sum == 0 && arr[0] == 0)
        {
            return 2;
        }
        // ? sum == 0 to waha idx per jo bhi element ho sum ke equal ho to 1 return karna hi
        if (sum == 0 || sum == arr[0])
        {
            return 1;
        }
        // aur kuch bhi ho toh zero return kr do
        return 0;
    }
    if (dp[idx][sum] != -1)
    {
        return dp[idx][sum];
    }
    int notPick = solve(idx - 1, dp, arr, sum);
    int pick = 0;
    if (arr[idx] <= sum)
    {
        pick = solve(idx - 1, dp, arr, sum - arr[idx]);
    }
    return dp[idx][sum] = (notPick % mod + pick % mod) % mod;
}
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, dp, arr, k);
}

// ? tabulation code

int findWays_tabluation(vector<int> &num, int tar)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    if (num[0] == 0)
        dp[0][0] = 2; // 2 cases -pick and not pick
    // *else case ka matlab num[0] per kuch bhi ho aur sum 0 ho chhod do matlab ak choice
    else
        dp[0][0] = 1; // 1 case - not pick

    // * 2nd base case ->> ye toh pahle hi handle kr liya hu
    if (num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1; // 1 case -pick

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= tar; target++)
        {

            int notTaken = dp[ind - 1][target];

            int taken = 0;
            if (num[ind] <= target)
                taken = dp[ind - 1][target - num[ind]];

            dp[ind][target] = (notTaken + taken) % mod;
        }
    }
    return dp[n - 1][tar];
}

// * space optimization code
int findWays_spaceOptimization(vector<int> &num, int tar)
{
    int n = num.size();

    vector<int> prev(tar + 1, 0);

    if (num[0] == 0)
        prev[0] = 2; // 2 cases -pick and not pick
    else
        prev[0] = 1; // 1 case - not pick

    if (num[0] != 0 && num[0] <= tar)
        prev[num[0]] = 1; // 1 case -pick

    for (int ind = 1; ind < n; ind++)
    {
        vector<int> cur(tar + 1, 0);
        for (int target = 0; target <= tar; target++)
        {
            int notTaken = prev[target];

            int taken = 0;
            if (num[ind] <= target)
                taken = prev[target - num[ind]];

            cur[target] = (notTaken + taken) % mod;
        }
        prev = cur;
    }
    return prev[tar];
}

int main()
{
    vector<int> arr = {0, 0, 1};
    int target = 1;
    cout << "Count subset with k sum -> " << findWays_spaceOptimization(arr, target) << "\n";
    return 0;
}