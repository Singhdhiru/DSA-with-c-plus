#include <iostream>
#include <vector>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn   : https://www.youtube.com/watch?v=LK0c7tCzKmM
    Company Tags                  : Google, Amazon, Microsoft, Ola Cabs, Qualcomm
    Leetcode Link                 : https://leetcode.com/problems/single-number-ii/
    GfG Link                      : https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1
*/

//*Approach-1
/*
    Simply maintain a unordered_map.
    Find the element having frequency 1
    Space Complexity = O(n)
    Time Complexity = O(n)
*/

//*Approach-2
/*
    Sort + Smart Traversal
    Time - O(nlogn)
    Space - No extra space
*/
//*Approach - 3 (Time Complexity : O(32*n))

// ! Better understanding ke liye example le lo aur sab ka binary likho aur analyze kro
// ? nums = {2,2,2,1,4,4,4};
int singleNumber(vector<int> &nums)
{
    int result = 0;
    for (int k = 0; k <= 31; k++) // k=bit present 0...32
    { 
        int temp = 1 << k; //? k=0 
        int countOnes = 0;
        int countZeros = 0;
        // * every element ke 0bit ko check karunag
        for (auto &num : nums)
        {
            if (num & temp)
            {
                countOnes++;
            }
            else
            {
                countZeros++;
            }
        }
        if (countOnes % 3 ==
            1)
        { // every ele is three time agar ones 3 se divide ho jayega
          // yani single ele jo hi usme 1 nahi toh use res mai koiee
          // fark nahi padega
            result = result | temp;  //? result = result | 1<<k ye bhi work karega
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {2, 2, 3, 2}; // Example input
    int result = singleNumber(nums);
    cout << "The single number is: " << result << endl;
    return 0;
}
