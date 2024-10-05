#include <bits/stdc++.h>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Za8V4wkZKkM
    Company Tags                : Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/maximum-sum-circular-subarray/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1
*/

/*


*Approach-1 (using rotate function)
*on submitting giving a tle
class Solution {
public:
    * ye roate karenge first element ko last mai dalenge
    void rotate(vector<int>&a,int n)
    {
        int temp=a[0];
        for(int i=0;i<n-1;i++)a[i]=a[i+1];
        a[n-1]=temp;
    }
    
    int kadanesMax(vector<int> &arr, int n)
    {
        int maxSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            maxSum = max(maxSum, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int result=INT_MIN;
        for(int i=0;i<n;i++)
        { 
            * rotate karenge aur each time masxSumSubbarry nikalenge 
            rotate(nums,n); //* rotate karnege jab tak orignal ke equal na ho jaye
            * kadanes algo se each time max niakleneg 
            result=max(result,kadanesMax(nums,n));
        }
        return result;
    }
};
*/
//*Approach-2 (Using Kadane's Algo) - O(N)
class Solution
{
public:
    int kadanesMax(vector<int> &arr, int n)
    {
        int maxSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            maxSum = max(maxSum, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxSum;
    }
    int kadanesMin(vector<int> &arr, int n)
    {
        int minSum = INT_MAX;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            minSum = min(minSum, sum);
            if (sum > 0)
            {
                sum = 0;
            }
        }
        return minSum;
    }
    int maxSubarraySumCircular(vector<int> &arr)
    {
        int n = arr.size();
        // 1 -> total sum of the  array
        int SUM = 0;
        for (int i = 0; i < n; i++)
        {
            SUM += arr[i];
        }

        // 2 -> minSum subarry using kadanes Algo
        int minSum = kadanesMin(arr, n);

        // 3 -> maxSUm subarry using kadanes Algo
        int maxSUm = kadanesMax(
            arr, n); // case 1 -> stright mai hi max sum subarray mil jaye

        // case 2 -> circular array mai maxSum mile
        int circular_sum = SUM - minSum;

        // edge case dekho ye wala
        //  arr-> {-1, -1, -1};
        if (maxSUm > 0)
        {
            return max(maxSUm, circular_sum);
        }
        return maxSUm;
    }
};

/*
  //*Approach-3 (Writing everything in one loop) - O(N)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n   = nums.size();
        int SUM = accumulate(begin(nums), end(nums), 0);

        int k_sum_min = nums[0];
        int min_sum   = nums[0];

        int k_sum_max = nums[0];
        int max_sum   = nums[0];

        for(int i = 1; i<nums.size(); i++) {

            min_sum   = min(nums[i]+min_sum, nums[i]);
            k_sum_min = min(k_sum_min, min_sum);

            max_sum = max(nums[i]+max_sum, nums[i]);
            k_sum_max = max(k_sum_max, max_sum);

        }

        int circular_sum = SUM - k_sum_min;

        if(k_sum_max > 0) {
            return max(k_sum_max, circular_sum);
        }

        return k_sum_max;

    }
};
*/
int main()
{
    Solution obj;
    vector<int> arr = {1, -2, 3, -2};
    cout << obj.maxSubarraySumCircular(arr) << endl;
    return 0;
}