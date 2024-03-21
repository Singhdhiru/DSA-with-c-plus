#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int cutRod(int price[], int N) {
    vector<vector<int>> dp(N, vector<int>(N + 1, 0));

    // base case
    // cut ka value 0 se actual length tak jayega
    for (int cut = 0; cut <= N; cut++) { //i am fill first row pf the dp;
        dp[0][cut] = cut * price[0];
    }
    // identify the stage and fill the entire dp
    for (int idx = 1; idx < N; idx++) {
        for (int cut = 0; cut <= N; cut++) {
            int notTake = dp[idx - 1][cut];
            int take = INT_MIN;
            int length = idx + 1;
            if (length <= cut) {
                take = price[idx] + dp[idx][cut - length];
            }
            dp[idx][cut] = max(notTake, take);
        }
    }
    return dp[N - 1][N];
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int N = sizeof(price) / sizeof(price[0]);
    cout << "Maximum obtainable value is " << cutRod(price, N) << endl;
    return 0;
}
