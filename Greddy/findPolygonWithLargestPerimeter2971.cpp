#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3RUkd0SPnPk
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/
*/
//T.C : O(nlogn)
//S.C : O(1)
long long largestPerimeter(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    long long perimeter = 0;
    long long remainingSideSum = 0; // cumulative sum

    for (int i = 0; i < n; i++) {
        if (nums[i] < remainingSideSum) {
            perimeter = remainingSideSum + nums[i];
        }
        remainingSideSum += nums[i];
    }

    return perimeter == 0 ? -1 : perimeter;
}
int main() {
    // Example usage
    vector<int> nums = {3, 6, 2, 3};  // Replace this with your input vector

    long long result = largestPerimeter(nums);

    if (result == -1) {
        cout << "No valid perimeter found." << endl;
    } else {
        cout << "Largest perimeter: " << result << endl;
    }

    return 0;
}

