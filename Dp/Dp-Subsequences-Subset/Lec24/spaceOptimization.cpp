#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// Space optimization using two 1d array it can solve also using 1 array
int cutRod(int price[], int N) {
    vector<int>prev(N+1,0);
    vector<int>curr(N+1,0);

    // base case
    // cut ka value 0 se actual length tak jayega
    for (int cut = 0; cut <= N; cut++) { //i am fill first row pf the dp;
        prev[cut] = cut * price[0];
    }
    // identify the stage and fill the entire dp
    for (int idx = 1; idx < N; idx++) {
        for (int cut = 0; cut <= N; cut++) {
            int notTake = prev[cut];
            int take = INT_MIN;
            int length = idx + 1;
            if (length <= cut) {
                take = price[idx] + curr[cut - length];
            }
            curr[cut] = max(notTake, take);
        }
        prev = curr;
    }
    return prev[N];
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int N = sizeof(price) / sizeof(price[0]);
    cout << "Maximum obtainable value is " << cutRod(price, N) << endl;
    return 0;
}
