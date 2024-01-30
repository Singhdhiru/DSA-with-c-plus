#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=-SWrz90jCUM
    Company Tags                : Amazon, Meta
    Leetcode Qn Link (560)           : https://leetcode.com/problems/subarray-sum-equals-k/
*/

// ? Brute Force
// ?T.C : o(n^2);
// ? S.C : 0(1);
int sumOfSubarryaEqualToK(vector<int> &nums, int k)
{
    int result = 0;
    int sum = 0;
    int n = nums.size();
    // generate all subaaray and chek the sum of subarray equal to k or not
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            // stating point i and ending point j ka sum nikalo aur compare kar lo
            for(int start = i; start<=j; start++){
                sum += nums[start];
            }
            if(sum == k){
                result += 1;
            }
        }
    }
    return result;
}
// optimnal solution
// T.C : O(n)
// S.C : O(n)
int subarraySum(vector<int> &nums, int k)
{
    int result = 0;
    int sum = 0;
    map<int, int> mp;
    // ? edge case hi ->> nums = {1,-1} ->> k = 0  ko dry run toh zero pahle se add karna padta hi tab sahi answer ata hi
    mp.insert({0, 1});
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        if (mp.count(sum - k))
            result += mp[sum - k];

        mp[sum]++;
    }
    return result;
}

int main()
{
    // Example usage:
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 7;
    // int result = subarraySum(nums, k);

    int result = sumOfSubarryaEqualToK(nums, k);

    cout << "The number of subarrays with sum " << k << " is: " << result << endl;

    return 0;
}