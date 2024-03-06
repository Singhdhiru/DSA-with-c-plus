#include <bits/stdc++.h>
using namespace std;
/*
*Time Complexity: O(N*T)
Reason: There are two nested loops.
*Space Complexity: O(T)
Reason: We are using two external arrays of size ‘T+1’.
*/
// Function to find the minimum number of elements needed to form the target sum
int minimumElements(vector<int>& arr, int T) {
    int n = arr.size();
    
    // Create two vectors to store the previous and current DP states
    vector<int> prev(T + 1, 0);
    vector<int> cur(T + 1, 0);
    
    // Initialize the first row of the DP table
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            prev[i] = i / arr[0];
        else
            prev[i] = 1e9; // Set it to a very large value if not possible
    }
    
    // Fill the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            // Calculate the minimum elements needed without taking the current element
            int notTake = prev[target];
            
            // Calculate the minimum elements needed by taking the current element
            int take = 1e9; // Initialize 'take' to a very large value
            if (arr[ind] <= target)
                take = 1 + cur[target - arr[ind]];
                
            // Store the minimum of 'notTake' and 'take' in the current DP state
            cur[target] = min(notTake, take);
        }
        // Update the previous DP state with the current state for the next iteration
        prev = cur;
    }
    
    // The answer is in the last row of the DP table
    int ans = prev[T];
    
    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9)
        return -1;
    
    return ans; // Return the minimum number of elements needed
}

int main() {
    vector<int> arr = {1, 2, 3};
    int T = 7;
    
    // Call the function to find the minimum number of elements needed
    int result = minimumElements(arr, T);
    
    // Output the result
    cout << "The minimum number of coins required to form the target sum is " << result << endl;
    
    return 0; // Return 0 to indicate successful program execution
}
