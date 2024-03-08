#include <bits/stdc++.h>
using namespace std;
// * https://leetcode.com/problems/coin-change-ii/description/
// ? Recursion + memoization
/*
*Time Complexity: O(N*T)
Reason: There are N*W states therefore at max ‘N*T’ new problems will be solved.
*Space Complexity: O(N*T) + O(N)
Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*T)).
*/
// Function to count the number of ways to make change for a given target sum
long countWaysToMakeChangeUtil(vector<int>& arr, int ind, int T, vector<vector<long>>& dp) {
    // Base case: if we're at the first element
    if (ind == 0) {
        // Check if the target sum is divisible by the first element
        return (T % arr[0] == 0);
    }
    
    // If the result for this index and target sum is already calculated, return it
    if (dp[ind][T] != -1)
        return dp[ind][T];
        
    // Calculate the number of ways without taking the current element
    long notTaken = countWaysToMakeChangeUtil(arr, ind - 1, T, dp);
    
    // Calculate the number of ways by taking the current element
    long taken = 0;
    if (arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr, ind, T - arr[ind], dp);
        
    // Store the sum of ways in the DP table and return it
    return dp[ind][T] = notTaken + taken;
}

// Function to count the number of ways to make change for the target sum
long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<vector<long>> dp(n, vector<long>(T + 1, -1)); // Create a DP table
    
    // Call the utility function to calculate the answer
    return countWaysToMakeChangeUtil(arr, n - 1, T, dp);
}

//* Tabulation Code
/*
*Time Complexity: O(N*T)
Reason: There are two nested loops
*Space Complexity: O(N*T)
Reason: We are using an external array of size ‘N*T’. Stack Space is eliminated.
*/
long countWaysToMakeChange_tabulation(vector<int>& arr, int n, int T) {
    vector<vector<long>> dp(n, vector<long>(T + 1, 0)); // Create a DP table

    // Initializing base condition
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            dp[0][i] = 1;
        // Else condition is automatically fulfilled,
        // as dp array is initialized to zero
    }

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            long notTaken = dp[ind - 1][target];

            long taken = 0;
            if (arr[ind] <= target)
                taken = dp[ind][target - arr[ind]];

            dp[ind][target] = notTaken + taken;
        }
    }

    return dp[n - 1][T];
}

// ? Space optimization
/*
*Time Complexity: O(N*T)
Reason: There are two nested loops.
*Space Complexity: O(T)
Reason: We are using an external array of size ‘T+1’ to store two rows only.
*/
long long int count_spaceOptimization(vector<int>&coins, int N, int sum) {
        vector<long long int >prev(sum+1, 0);
        vector<long long int>curr(sum+1, 0);
        for(int t=0; t<=sum; t++){
            if(t%coins[0] == 0){
                prev[t] = 1;
            }
        }
        for(int idx=1; idx<N; idx++){
            for(int t=0; t<=sum; t++){
                long long int nt = prev[t];
                long long int take = 0;
                if(coins[idx]<=t){
                    take = curr[t-coins[idx]];
                }
                curr[t] = nt+take;
            }
            prev = curr;
        }
        return prev[sum];
    }
int main() {
    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();
    
    cout << "The total number of ways is " << count_spaceOptimization(arr, n, target) << endl;

    return 0; // Return 0 to indicate successful program execution
}
