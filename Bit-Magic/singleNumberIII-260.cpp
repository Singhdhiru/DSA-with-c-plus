#include <iostream>
#include <vector>
using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=h1EVBhCMugI
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/single-number-iii/description/
    SIngle Number II Video      : https://www.youtube.com/watch?v=LK0c7tCzKmM
*/
// Approach (Optimal)
// T.C : O(n)
// S.C : O(1)
vector<int> singleNumber(vector<int> &nums)
{
    long long xor_r = 0;

    for (int &num : nums)
    {
        xor_r ^= num; // xor_r = 3^5 => 110 present hoga
    }
    // hame aieesa karna hi ki 3 and 5 alag group mai jaye
    // uske liye mask create kiya hu

    //? Approach ->01
    // mask -> right most set bit search
    // *int mask = (xor_r) & (-xor_r);
    /*
        It works because if you take the two's complement negation of a
       number, first you complement it, setting all zeroes to the right of
       the lowest set bit to one and the lowest set bit to zero, then you
       add one, setting the bits on the right to zero and the lowest set bit
       becomes one again, ending the carry chain.
    */

    //*  Approach ->02 to create mask
    int mask = 1;
    int shift = 0;

    // Find the rightmost set bit in xor_r
    while (xor_r)
    {
        if (xor_r & 1)
        {
            break;
        }
        else
        {
            shift++;
        }
        xor_r >>= 1; // Shift right to find the rightmost set bit
    }

    // Create a mask for the rightmost set bit
    mask <<= shift;

    int groupa = 0;
    int groupb = 0;

    for (int &num : nums)
    {
        if (num & mask)
        {
            groupa ^= num;
        }
        else
        {
            groupb ^= num;
        }
    }

    return {groupa, groupb};
}
int main()
{
    vector<int> nums = {1, 2, 1, 3, 2, 5}; // Example input
    vector<int> result = singleNumber(nums);

    cout << "The two single numbers are: " << result[0] << " and " << result[1] << endl;

    return 0;
}
