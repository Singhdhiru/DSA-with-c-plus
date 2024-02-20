#include <bits/stdc++.h>
using namespace std;
/*
?Why Use this AlgoRithm      : https://www.codingninjas.com/studio/library/moore-s-voting-algorithm
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Q6L5SoS-fTo
    Company Tags                : Amazon, Google
    Leetcode Qn Link            : https://leetcode.com/problems/majority-element-ii/
*/
// ? Approach 1  : Using hash Map
// ? TC          : O(n)
// ? SC          : 0(1)

vector<int> majorityElement_hashMap(vector<int>nums){
    unordered_map<int, int>mp;
    int n = nums.size();
    vector<int>res;
    for(auto &it : nums){
        mp[it]++;
    }
    for(auto &it : mp){
        if(it.second>(n/3)){
            res.push_back(it.first);
        }
    }
    return res;
}
// ? Approach 2  : using Moore Voting Algorithm
// ? TC          : O(n)
// ? SC          : O(1)
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();

    int maj1 = -1;
    int count1 = 0;

    int maj2 = -1;
    int count2 = 0;
    int freq = floor(n / 3);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == maj1)
            count1++;
        else if (nums[i] == maj2)
            count2++;
        else if (count1 == 0)
        {
            maj1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            maj2 = nums[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    vector<int> result; // because atmost two elements can occur more than ⌊ n/3 ⌋ in an array of length n
    count1 = 0;
    count2 = 0;
    for (int num : nums)
    {
        if (num == maj1)
            count1++;
        else if (num == maj2)
            count2++;
    }
    if (count1 > floor(n / 3))
        result.push_back(maj1);
    if (count2 > floor(n / 3))
        result.push_back(maj2);
    return result;
}
int main()
{
    string str = "";
    vector<int> nums = {3,2,3};
    int n = nums.size();
    vector<int> ans = majorityElement_hashMap(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}