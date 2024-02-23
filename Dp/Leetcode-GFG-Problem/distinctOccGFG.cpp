#include<bits/stdc++.h>
using namespace std;
/*
gfg      :  https://www.geeksforgeeks.org/problems/distinct-occurrences/1
*/
// * space complexity : O(n * m)
// * time complexity  :  O(n * m)
int solve(int i, int j, string &a, string &b, int n, int m, vector<vector<int>> &dp) {
    // * j jabb m tak pahuch gaya yani 1 match to mil gaya hi
    if (j == m) {
        return 1;
    }
    if (i == n) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = 0;
    if (a[i] != b[j]) {
        ans = solve(i + 1, j, a, b, n, m, dp);
    } else {
        int take = solve(i + 1, j + 1, a, b, n, m, dp);
        int notTake = solve(i + 1, j, a, b, n, m, dp);
        ans = take + notTake;
    }
    dp[i][j] = ans;
    return ans;
}

int distinctOccurences(string &a, string &b, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(0, 0, a, b, n, m, dp);
}

int main() {
    string a = "abcbc";
    string b = "abc";
    int n = a.length();
    int m = b.length();

    int result = distinctOccurences(a, b, n, m);

    cout << "Number of distinct occurrences: " << result << endl;

    return 0;
}