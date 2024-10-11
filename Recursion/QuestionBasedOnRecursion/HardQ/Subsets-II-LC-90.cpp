#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void findSubset(int idx, vector<int> nums, vector<int> &temp,
                    vector<vector<int> > &ans)
    {
        ans.push_back(temp);
        for (int i = idx; i < nums.size(); i++)
        {
            if (i != idx && nums[i] == nums[i - 1])
            {
                continue;
            }
            temp.push_back(nums[i]);
            findSubset(i + 1, nums, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &arr)
    {
        sort(begin(arr), end(arr));
        vector<vector<int> > ans;
        vector<int> temp;
        findSubset(0, arr, temp, ans);
        return ans;
    }
};

int main()
{
    Solution solution;

    // Example input
    vector<int> arr = {1, 2, 2};

    // Get subsets
    vector<vector<int> > result = solution.subsetsWithDup(arr);

    // Print results
    cout << "Subsets with duplicates:" << endl;
    for (const auto &subset : result)
    {
        cout << "{ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}