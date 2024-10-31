#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Approach-> 1st
class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);
        // Calculate LIS
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] > nums[j])
                {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }
        // Calculate LDS
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] > nums[j])
                {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }
        // Formula->
        // idx(i)-> is peak element
        // left Side-> totalEleInleftSide(i)-LIS[i]+1(for peak element)
        // RightSide-> (n-i)-LDS[i]
        // TotalRemoval = leftside+Rightside
        // Drive Formula->n-LIS[i]-LDS[i]+1
        int minRemoval = n;
        for (int i = 0; i < n; i++)
        { // Treat all idx as a peak element in the array
            if (LIS[i] > 1 && LDS[i] > 1)
            { // atleat 3 element hona hi cahiye
                minRemoval = min(minRemoval, (n - LIS[i] - LDS[i] + 1));
            }
        }
        return minRemoval;
    }
};

int main()
{
    Solution solution;

    // Example input
    vector<int> nums = {2, 1, 1, 5, 6, 2, 3, 1};

    // Calculate minimum mountain removals
    int result = solution.minimumMountainRemovals(nums);

    // Output the result
    cout << "Minimum removals to make the array a mountain: " << result << endl;

    return 0;
}