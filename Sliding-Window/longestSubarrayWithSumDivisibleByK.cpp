#include <iostream>
#include <unordered_map>
using namespace std;
// video link->> https://www.youtube.com/watch?v=yKEAMVRlrh0
int longSubarrWthSumDivByK(int arr[], int n, int k) {
    // Map to store remainder and its corresponding index
    unordered_map<int, int> mp;

    // Initialize variables for maximum length and cumulative sum
    int mx = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        // Calculate cumulative sum
        sum += arr[i];

        // Calculate remainder when divided by K
        int rem = sum % k;

        // Check if the current subarray from the beginning is divisible by K
        if (rem == 0) {
            mx = max(mx, i + 1); // i = 0 then i use i+1
        }

        // Handle negative remainders
        if (rem < 0) {
            rem += k;
        }

        // If the remainder is not in the map, add it with its index
        if (mp.find(rem) == mp.end()) {
            mp[rem] = i;
        } else {
            // If the remainder is already in the map, update the maximum length
            int len = i - mp[rem];
            mx = max(mx, len);
        }
    }

    return mx;
}

int main() {
    // Example usage
    int arr[] = {4, 5, 0, -2, -3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;

    // Function call
    int result = longSubarrWthSumDivByK(arr, n, k);

    // Output the result
    cout << "Length of the longest subarray with sum divisible by K: " << result << endl;

    return 0;
}
