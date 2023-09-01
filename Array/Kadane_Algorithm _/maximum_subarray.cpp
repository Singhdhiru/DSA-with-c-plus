// using two for loop t.c-> t.c(n^2)

// #include <bits/stdc++.h>
// using namespace std;

// int maxSubarraySum(int arr[], int n) {
//     int maxi = INT_MIN; // maximum sum

//     for (int i = 0; i < n; i++) {
//         int sum = 0;
//         for (int j = i; j < n; j++) {
//              current subarray = arr[i.....j]

//             add the current element arr[j]
//              to the sum i.e. sum of arr[i...j-1]
//             sum += arr[j];

//             maxi = max(maxi, sum); // getting the maximum
//         }
//     }

//     return maxi;
// }

// int main()
// {
//     int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int maxSum = maxSubarraySum(arr, n);
//     cout << "The maximum subarray sum is: " << maxSum << endl;
//     return 0;
// }


// using kadane's algorithm ->> t.c(n)
#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
