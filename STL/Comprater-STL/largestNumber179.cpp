/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=oJyl4fbfpM0
    Company Tags                : Microsoft, Amazon, MakeMyTrip, Paytm, Zoho, Goldman Sachs
    Leetcode Link               : https://leetcode.com/problems/largest-number/
    Similar GFG Problem         : https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
*/
// Leetcode Version
// T.C : O(nlogn)
// S.C : O(1) (I am ignoring the space taken by result of size n which we have to return
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ! lamda expression 
static bool myFunction(int a, int b)
{
    // Convert integers to strings
    string s1 = to_string(a);
    string s2 = to_string(b);

    return (s1 + s2) > (s2 + s1);
}

string largestNumber(vector<int> &nums)
{
    
    // Sort the numbers using the custom comparator
    sort(nums.begin(), nums.end(), myFunction);

    // If the largest number is 0, return "0"
    if (nums[0] == 0)
        return "0";

    // Concatenate the sorted numbers to form the result
    string result = "";
    for (int i : nums)
        result += to_string(i);

    return result;
}

int main()
{
    vector<int> numbers = {3, 30, 34, 5, 9}; // Replace this with your own input

    // Find and display the largest number
    string result = largestNumber(numbers);
    cout << "Largest Number: " << result << endl;

    return 0;
}
