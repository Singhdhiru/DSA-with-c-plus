/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=kCxCE0_66vM
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/grumpy-bookstore-owner
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//*Approach - Sliding Window(fixed Lenght)
// T.C : O(n)
// S.C : O(1)
int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
{
    int currUns = 0;
    int n = customers.size();
    // first fixed lenght ka nikal liya
    for (int i = 0; i < minutes; i++)
    {
        if (grumpy[i] == 1)
        {
            currUns += customers[i];
        }
        // if condition ko one line ,ai bhi likh sakte hi
        // currUns += customers[i]*grumpy[i];
    }
    int maxUns = currUns;
    int i = 0;
    int j = minutes;
    while (j < n)
    {
        // if(grmupy[j] == 1) means customers are not haapy usse add kro
        currUns += customers[j] * grumpy[j]; // Include current element
        // if(grump[i] == 0) means customers are happy usse CurrUns mai kyu add karunga usse sub kro
        currUns -= customers[i] * grumpy[i]; // Remove element going out of window
        maxUns = max(maxUns, currUns);       // Update maxUnsat
        i++;
        j++;
    }
    int totalCustomer = maxUns;
    for (int i = 0; i < n; i++)
    {
        totalCustomer += customers[i] * (1 - grumpy[i]);
        // other method to write above line
        // if(grumpy[i] == 0){
        //     totalCustomer += customers[i];
        // }
    }
    return totalCustomer;
}

int main()
{
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;

    int result = maxSatisfied(customers, grumpy, minutes);
    cout << "Maximum number of satisfied customers: " << result << endl;

    return 0;
}
