// 643. Maximum Average Subarray I

#include <iostream>
#include <vector>

using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
    int n = nums.size();
    int sum = 0;

    // Calculate the sum of the first k elements
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }

    double max_avg = static_cast<double>(sum) / k;

    // Iterate through the array from index k to the end
    for (int i = k; i < n; i++)
    {
        sum = sum - nums[i - k] + nums[i];
        max_avg = max(max_avg, static_cast<double>(sum) / k);
    }

    return max_avg;
}
int main()
{
    // Example usage of the findMaxAverage function
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double result = findMaxAverage(nums, k);

    cout << "Maximum average of subarrays of length " << k << " is: " << result << endl;

    return 0;
}
