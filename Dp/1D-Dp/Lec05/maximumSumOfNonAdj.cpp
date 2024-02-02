
#include <bits/stdc++.h>
using namespace std;

// recursion solution give mt tle  -> 2^N(exponentional)
// int solve(int idx, vector<int>& arr){
//     if(idx == 0)return arr[idx];
//     if(idx < 0) return 0;
//     int pick = arr[idx]+solve(idx-2, arr);
//     int notPick = 0+solve(idx-1, arr);
//     return max(pick, notPick);
// }
// int maximumNonAdjacentSum(vector<int> &nums){
//     int n= nums.size();
//     return solve(n-1, nums);
// }

// ? dp(memoization technique) linear 0(N)
int solve(int idx, vector<int>& arr, vector<int>& dp){
    if(idx == 0)return arr[idx];
    if(idx < 0) return 0;
    if(dp[idx] != -1)return dp[idx];
    int pick = arr[idx]+solve(idx-2, arr, dp);
    int notPick = 0+solve(idx-1, arr, dp);
    return dp[idx] = max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n= nums.size();
    vector<int> dp(n, -1);
    return solve(n-1, nums, dp);
}

int main() {
    vector<int> arr{2, 1, 4, 9};
    // Call the solve function and print the result
    cout << maximumNonAdjacentSum( arr);

    return 0;
}
