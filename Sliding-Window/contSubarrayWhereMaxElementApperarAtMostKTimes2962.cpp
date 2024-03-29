#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>

using namespace std;
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=06VaWkj8e-0
      Company Tags                : will update soon
      Leetcode Link               : https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
*/
//*Approach-1 (Classic sliding window)
// T.C : O(n)
// S.C : O(1)
long long countSubarrays(vector<int> &nums, int k)
{
    int maxE = *max_element(begin(nums), end(nums));

    int n = nums.size();
    int i = 0, j = 0;

    long long result = 0;
    int countMax = 0;

    while (j < n)
    {
        if (nums[j] == maxE)
        {
            countMax++;
        }

        while (countMax >= k)
        {
            result += n - j;

            if (nums[i] == maxE)
            {
                countMax--;
            }
            i++;
        }
        j++;
    }

    return result;
}

//*Approach-2 (Without Sliding Window)
// T.C : O(n)
// S.C : O(n)
long long countSubarrays(vector<int> &nums, int k)
{
    int maxE = *max_element(begin(nums), end(nums));

    int n = nums.size();

    long long result = 0;

    vector<int> maxIndices;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == maxE)
        {
            maxIndices.push_back(i);
        }

        int size = maxIndices.size();
        if (size >= k)
        {
            // * pichhe dekhunga last idx jaha jane per maxE k  ke equal ho raha hi
            int last_i = maxIndices[size - k];
            result += last_i + 1;
        }
    }

    return result;
}
int main()
{
    // Example usage:
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2; //? maximum ele = 3 yani kitna subaaray mai 2 ya 2 se jayda baar aayega
    cout << "Max subarray length with each element occurring exactly " << k << " times: " << countSubarrays(nums, k) << endl;
    return 0;
}
