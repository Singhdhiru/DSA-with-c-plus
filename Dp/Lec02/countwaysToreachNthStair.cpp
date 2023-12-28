// Steps for the Tabulation approach.

// Declare a dp[] array of size n+1.
// First initialize the base condition values, i.e i=0 and i=1 of the dp array as 1.
// Set an iterative loop that traverses the array( from index 2 to n) and for every index set its value as dp[i-1] + dp[i-2].

#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n = 3;
    vector<int> dp(n + 1, -1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    return 0;
}