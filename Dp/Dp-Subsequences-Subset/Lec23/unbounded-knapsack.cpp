#include <bits/stdc++.h>
using namespace std;
//? : https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
/*
*Time Complexity: O(N*W)
Reason: There are N*W states therefore at max ‘N*W’ new problems will be solved.
*Space Complexity: O(N*W) + O(N)
Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).
*/
// Function to solve the unbounded knapsack problem
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
    // Base case: if we're at the first item
    if (ind == 0) {
        // Calculate and return the maximum value for the given weight limit
        return (W / wt[0]) * val[0];
    }
    
    // If the result for this index and weight limit is already calculated, return it
    if (dp[ind][W] != -1)
        return dp[ind][W];
        
    // Calculate the maximum value without taking the current item
    int notTaken = 0 + knapsackUtil(wt, val, ind - 1, W, dp);
    
    // Calculate the maximum value by taking the current item
    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);
        
    // Store the maximum value in the DP table and return it
    return dp[ind][W] = max(notTaken, taken);
}

// Function to solve the unbounded knapsack problem
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1)); // Create a DP table
    
    // Call the utility function to calculate the maximum value
    return knapsackUtil(wt, val, n - 1, W, dp);
}

int main() {
    vector<int> wt = {2, 4, 6}; // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10; // Weight capacity of the knapsack
    int n = wt.size(); // Number of items
    
    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack(n, W, val, wt) << endl;

    return 0; // Return 0 to indicate successful program execution
}
