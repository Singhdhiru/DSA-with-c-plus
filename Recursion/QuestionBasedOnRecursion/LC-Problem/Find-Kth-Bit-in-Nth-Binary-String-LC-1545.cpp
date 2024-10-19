#include <iostream>
#include <math.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=z4gmEqrhrkE
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-kth-bit-in-nth-binary-string
*/
//*  Brute force
class Solution
{

private:
    string mani(string t)
    {
        for (auto &c : t)
        {
            if (c == '0')
                c = '1';
            else
                c = '0';
        }
        reverse(t.begin(), t.end());
        return t;
    }

    string Solve(int n, vector<string> &dp)
    {
        if (n == 1)
            return "0";
        if (dp[n] != "-1")
            return dp[n];
        return dp[n] = Solve(n - 1, dp) + "1" + mani(Solve(n - 1, dp));
    }

public:
    char findKthBit(int n, int k)
    {
        vector<string> dp(n + 1, "-1");
        string ans = Solve(n, dp);
        return ans[k - 1];
    }
};

//*Approach - Recursion
// T.C : O(n)
// S.C : O(n)
class Solution2
{
public:
    char findKthBit(int n, int k)
    {

        if (n == 1)
        {
            return '0';
        }

        int length = (1 << n) - 1; // pow(2, n) - 1

        if (k < ceil(length / 2.0))
        {
            return findKthBit(n - 1, k);
        }
        else if (k == ceil(length / 2.0))
        {
            return '1';
        }
        else
        {
            char ch = findKthBit(n - 1, length - (k - 1)); // handled reversed
            return (ch == '0') ? '1' : '0';                // handled flipped bit
        }
    }
};
int main()
{
    int n = 4;
    int k = 11;
    // Approach 1
    Solution sol1;
    cout << "kth bit in Sn string -> " << sol1.findKthBit(n, k) << endl;
    
    Solution2 sol;
    cout << "kth bit in Sn string -> " << sol.findKthBit(n, k) << endl;
    return 0;
}