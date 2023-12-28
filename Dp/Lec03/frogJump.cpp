
#include <bits/stdc++.h>

using namespace std;


// recursion  solution give me tle
// int f(int idx, vector<int>& height){
//     if(idx == 0){
//         return 0;
//     }

//     int left = f(idx-1, height)+abs(height[idx]-height[idx-1]);
//     int right= INT_MAX;
//     if(idx>1)right = f(idx-2, height)+abs(height[idx]-height[idx-2]);
//     return min(left, right);
// }
// int frogJump(int n, vector<int> &heights)
// {
//     return f(n-1, heights);
// }


int solve(int ind, vector<int> &height, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
    if (ind > 1)
        jumpTwo = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);

    return dp[ind] = min(jumpOne, jumpTwo);
}

int main()
{

    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n, -1);
    cout << solve(n - 1, height, dp);
}
// t.c-> 0(N);
// S.C-> 0(N);