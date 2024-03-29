#include<bits/stdc++.h>
using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Yatra
    Leetcode Link               : https://leetcode.com/problems/subarray-product-less-than-k/
*/
//*Approach  : Standard Sliding window Problem
//T.C : O(N)
//S.C : O(1)
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k <= 1)
        return 0;
    int n = nums.size();
    int count = 0;
    
    int left = 0;
    int right = 0;
    int prod = 1;
    
    while(right < n){
        prod *= nums[right];
        
        // ? shirnk kro window ko
        while(prod >= k) {
            // product ko divide kr do jo left wale element se
            prod /= nums[left];
            left++;
        }
        // * subaary nikal jayega total
        count += (right-left)+1;
        right++;
    }
    return count;
}

int main() {
    // Example usage:
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << "Number of subarrays with product less than " << k << ": " << numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}