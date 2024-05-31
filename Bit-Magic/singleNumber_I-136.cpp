#include <iostream>
#include <vector>
using namespace std;
// * https://leetcode.com/problems/single-number/description/
int singleNumber(vector<int>& nums) {
    int res = 0;
    for(int i = 0; i < nums.size(); i++) {
        res ^= nums[i];
    }
    return res;
}

int main() {
    
    vector<int>nums = {4,1,2,1,2};
    int result = singleNumber(nums);
    cout << "The single number is: " << result << endl;

    return 0;
}
