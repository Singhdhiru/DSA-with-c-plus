#include<bits/stdc++.h>
using namespace std;
/*
Leetcode   : 78. Subsets
video Link : https://www.youtube.com/watch?v=b7AYbpM5YrE
*/
void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    //? base case
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    //? exclude
    solve(nums, output, index + 1, ans);

    //? include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1, ans);
}
vector<vector<int>> subsets(vector<int> &nums)
{

    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}
int main() {
    vector<int>nums = {1,2,3};
    int  n = nums.size();
    vector<vector<int>> ans = subsets(nums);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
