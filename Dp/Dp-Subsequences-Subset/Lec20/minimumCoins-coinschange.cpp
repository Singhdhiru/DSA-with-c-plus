#include <bits/stdc++.h> // Include necessary libraries
using namespace std;
/*
*Time Complexity: O(N*T)
Reason: There are N*T states therefore at max ‘N*T’ new problems will be solved.
*aSpace Complexity: O(N*T) + O(N)
Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*T)).
*/
int solve(int idx, int T, vector<int>& coins, vector<vector<int>>&dp) {
        // base case
        if (idx == 0) {
            //? baes case mai ak element ko lekar kr check kiya kro
            //? if ak element coins se divisible se hi toh use lelo n ans mai
            if (T % coins[idx] == 0) {
                return T / coins[idx];
            }
            // agar divisible n ho toh koiee bada number lena agar zero lenge
            // toh to o count ho jayega
            else {
                return 1e9;
            }
        }
        if(dp[idx][T] != -1){
            return dp[idx][T];
        }
        int nT = 0+solve(idx-1,T, coins,dp);
        int take = 1e9;
        if(coins[idx]<=T){
            take = 1 + solve(idx, T-coins[idx],coins,dp);
        }
        return dp[idx][T] =  min(nT, take);
    }

// Function to find the minimum number of elements needed to form the target sum
int minimumElements(vector<int> &arr, int T)
{

    int n = arr.size();

    // Create a DP (Dynamic Programming) table with n rows and T+1 columns and initialize it with -1
    vector<vector<int>> dp(n, vector<int>(T + 1, -1));

    // Call the utility function to calculate the answer
    int ans = solve(n-1, T, arr, dp);

    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9)
        return -1;
    return ans; // Return the minimum number of elements needed
}

int main()
{

    vector<int> arr = {1, 2, 3};
    int T = 7;

    cout << "The minimum number of coins required to form the target sum is " << minimumElements(arr, T);

    return 0; // Return 0 to indicate successful program execution
}
