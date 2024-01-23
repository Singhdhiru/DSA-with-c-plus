#include <iostream>
#include <vector>
#include <unordered_map>
#include<map>
using namespace std;
// ? 645. Set Mismatch

//?Approach-1 (Basic Approach)
//?T.C : O(n)
//?S.C : O(n)
vector<int> findErrorNums_basicApporach(vector<int> &nums)
{
    int n = nums.size();
    int miss = 0, dup = 0;

    map<int, int> mp;
    for (int x : nums)
    {
        mp[x]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (mp.count(i))
        {
            if (mp[i] == 2)
                dup = i;
        }
        else
            miss = i;
    }

    return {dup, miss};
}

//?Approach-2 (Smart Approach)
//?T.C : O(n)
//?S.C : O(1)

vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup     = -1;
        int missing = -1;
        // ? main thinking->> isme n nuber hi diya hi->jo idx bhi bn sakta hi
        for(int i = 0; i<n; i++) {
            int num = abs(nums[i]);
            // ? 1 2 3 3 5->> second 3 per hi
            // ? nums[3-1]->> wo pahle se hi negative yani ye 3 dusre baar aa raha hi
            if(nums[num-1] < 0)
                dup = num;
            else
                nums[num-1] *= (-1);
        }

        for(int i = 0; i<n; i++) {
            // ? koieee idx per postive number iska matlab uske aage wala idx+1 value nahi present hi nahi to o negative ho jata
            if(nums[i] > 0) {
                missing = i+1;
                break;
            }
        }
        return {dup, missing};
    }
int main()
{
    vector<int>arr = {1,2,3,3,5};
    vector<int>ans = findErrorNums(arr);
    cout<<"Duplicate number is-> "<<ans[0]<<endl;
    cout<<"Missiing numberis-> "<<ans[1]<<endl;
    return 0;
}