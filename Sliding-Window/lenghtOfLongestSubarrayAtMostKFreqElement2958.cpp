#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=txSMzRMREKA
    Company Tags                :
    Leetcode Link               : https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
*/
//*Approach-1 (With Nested Loop - Classic Sliding Window Template)
// T.C : O(n)a
// S.C : O(n)
int maxSubarrayLength_a(vector<int> &nums, int k)
{
    int n = nums.size();

    unordered_map<int, int> mp;

    int i = 0;
    int j = 0;
    int result = 0;

    while (j < n)
    {

        mp[nums[j]]++;
        // * Window ko shirnk kar raha hu
        while (i < j && mp[nums[j]] > k)
        {
            mp[nums[i]]--;
            i++;
        }
        // ? maxumum ans hamesa update kar raha hu
        result = max(result, j - i + 1);
        j++;
    }

    return result;
}
//*Approach-2 (Without nested loop)
// T.C : O(n)
// S.C : O(n)

int maxSubarrayLength(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    int i = 0;
    int j = 0;
    int result = 0;

    int culprit = 0;

    while (j < n)
    {

        mp[nums[j]]++;
        if (mp[nums[j]] == k + 1)
        {
            culprit++;
        }

        if (culprit > 0)
        {
            mp[nums[i]]--;
            if (mp[nums[i]] == k)
            {
                culprit--;
            }
            i++;
        }

        if (culprit == 0)
        {
            result = max(result, j - i + 1);
        }
        j++;
    }

    return result;
}

int main()
{
    // Example usage:
    vector<int> nums = {1, 2, 1, 2, 3, 3, 3};
    int k = 2;
    cout << "Max subarray length with each element occurring exactly " << k << " times: " << maxSubarrayLength(nums, k) << endl;
    return 0;
}
