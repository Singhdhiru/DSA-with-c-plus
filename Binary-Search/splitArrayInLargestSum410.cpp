#include <bits/stdc++.h>
using namespace std;
/*
Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countPartitions() function for the value of ‘mid’. Now, inside the countPartitions() function, we are using a loop that runs for N times.

Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/
//* Question->> https://leetcode.com/problems/split-array-largest-sum/
int isPossiblePartition(vector<int> nums, int maxSum)
{
    int n = nums.size();
    int partition = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++)
    {
        if (subarraySum + nums[i] <= maxSum)
        {
            // insert element in the next subarray
            subarraySum += nums[i];
        }
        else
        {
            // add element in the next subarray
            partition++;
            subarraySum = nums[i];
        }
    }
    return partition;
}
int splitArray(vector<int> &nums, int k)
{
    int low = *max_element(begin(nums), end(nums));
    int high = accumulate(begin(nums), end(nums), 0);
    // apply Binary Search
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int partition = isPossiblePartition(nums, mid);
        if (partition > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = splitArray(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
