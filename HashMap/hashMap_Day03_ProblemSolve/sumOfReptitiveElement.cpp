#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int sumOfRepetitiveEle(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (auto x : nums) {
        mp[x]++;
    }
    int sum = 0;
    for (auto x : mp) {
        if (x.second > 1) {
            sum += x.first;
        }
    }

    return sum;
}

int main() {
    // Example usage of the sumOfUnique function
    vector<int> nums = {1, 2, 2, 3, 4, 4, 5, 5, 6, 7};
    int result = sumOfRepetitiveEle(nums);
    cout << "Sum of unique elements: " << result << endl;

    return 0;
}
