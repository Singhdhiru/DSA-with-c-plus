#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void generatePermutations(vector<int> &nums, vector<vector<int>> &result, int left, int right)
{
    if (left == right)
    {
        result.push_back(nums);
        return;
    }
    for (int i = left; i <= right; i++)
    {
        swap(nums[left], nums[i]);
        generatePermutations(nums, result, left + 1, right);
        swap(nums[left], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    generatePermutations(nums, result, 0, nums.size() - 1);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);
    for (vector<int> permutation : result)
    {
        for (int num : permutation)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
