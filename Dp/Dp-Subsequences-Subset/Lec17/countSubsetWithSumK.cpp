#include <bits/stdc++.h>
using namespace std;

/*
*Time Complexity: O(N*K)

Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved.

*Space Complexity: O(N*K) + O(N)

Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).
*/
// ! ye code fail ho jayega agar constrain 0<= arr[i] per striver ne 1<<arr[i] tak banaya hi isko fix karne ke liye ->> modifiedQuestion wale file mai dekho
int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // Base case: If the target sum is 0, we found a valid subset
    if (target == 0)
        return 1;

    // Base case: If we have considered all elements and the target is still not 0, return 0
    if (ind == 0)
        return (arr[0] == target) ? 1 : 0;

    // If the result for this state is already calculated, return it
    if (dp[ind][target] != -1)
        // return dp[ind][target];
        // * isko aiese bhi likh sakye hi
        return (arr[0] == target) ? 1:0;

    // Recursive cases
    // 1. Exclude the current element
    int notTaken = findWaysUtil(ind - 1, target, arr, dp);

    // 2. Include the current element if it doesn't exceed the target
    int taken = 0;
    if (arr[ind] <= target)
        taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

    // Store the result in the DP table and return
    return dp[ind][target] = notTaken + taken;
}

// Function to count the number of subsets with a given sum
int findWays(vector<int>& num, int k) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return findWaysUtil(n - 1, k, num, dp);
}

int main() {
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout << "The number of subsets found are " << findWays(arr, k);

    return 0;
}
