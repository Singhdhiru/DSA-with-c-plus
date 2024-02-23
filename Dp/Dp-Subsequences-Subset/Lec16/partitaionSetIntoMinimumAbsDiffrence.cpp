#include <bits/stdc++.h>
using namespace std;

// * gfg   : https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
// * codeS : https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos

// ? Approach ->> Tabulation method
/*
*Time Complexity: O(N*K) +O(N)
Reason: There are two nested loops that account for O(N*K) and at starting we are running a for loop to calculate totSum.
*Space Complexity: O(N*K)
Reason: We are using an external array of size ‘N*K’. Stack Space is eliminated.
*/
int minDifference(vector<int> &arr, int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        k += arr[i];
    }
    // vector<vector<bool,bool>>dp(n+1, vector,int>(k+1),false);
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // B.S 1 idx kuch ho target agar 0 target 0 ho toh hamesa true hoga
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    // B.S -> 2 -> agr idx 0 per ho wo kudh target ke equal ho
    if (arr[0] <= k)
    {
        dp[0][arr[0]] = true;
    }
    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 1; target < k; target++)
        {
            int notTake = dp[idx - 1][target];
            int take = false;
            if (arr[idx] <= target)
            {
                take = dp[idx - 1][target - arr[idx]];
            }
            dp[idx][target] = take || notTake;
        }
    }
    int mini = 1e9;
    for (int target = 0; target < k; target++)
    {
        if (dp[n - 1][target] == true)
        {
            int s1 = target;
            int s2 = k - s1;
            mini = min(mini, abs(s1 - s2));
        }
    }
    return mini;
}

// ? Approach -> 02 Sapce optimization
/*
*Time Complexity: O(N*K) +O(N)
Reason: There are two nested loops that account for O(N*K) and at starting we are running a for loop to calculate totSum.

*Space Complexity: O(K)
Reason: We are using an external array of size ‘K+1’ to store only one row.
*/
int minDiff(vector<int> &arr, int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        k += arr[i];
    }
     // Initialize a vector 'prev' to store the previous row of the DP table
    vector<bool> prev(k + 1, false);

    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    prev[0] = true;

    // Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }

    // Iterate through the elements of 'arr' and update the DP table
    for (int ind = 1; ind < n; ind++) {
        // Initialize a new row 'cur' to store the current state of the DP table
        vector<bool> cur(k + 1, false);

        // Base case: If the target sum is 0, we can achieve it by taking no elements
        cur[0] = true;

        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = prev[target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = prev[target - arr[ind]];
            }

            // Store the result in the current DP table row for the current subproblem
            cur[target] = notTaken || taken;
        }

        // Update 'prev' with the current row 'cur' for the next iteration
        prev = cur;
    }

    int mini = 1e9;
    for(int target =0 ;target<k; target++){
        if(prev[target] == true){
            mini = min(mini, k-target);
        }
    }
    return mini;
}
int main()
{
    // Example usage
    vector<int> arr = {3, 2, 7};
    int result = minDiff(arr, arr.size());
    cout << "Minimum Difference: " << result << endl;

    return 0;
}