// recursion ->>> tabulation(bottom Apporoach) ->> base csae to required answer
// #include <iostream>
// #include<vector>
// using namespace std;

// int main() {
//     int n = 5;
    // create dp array
//     vector<int>dp(n+1, -1);
//     dp[0] = 0;
//     dp[1] = 1;
    // apply simple iteration function
//     for(int i=2; i<=n; i++){
//         dp[i] = dp[i-1]+dp[i-2];
//     }
//     cout<<"nth fiboonacci number->> "<<dp[n]<<endl;
//     return 0;
// }
// Time complexity ->. 0(N);
// space complexity ->. 0(N);

// optimize sapce otimization
// 0(n) ->> 0(1)

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int prev2 = 0;
    int prev = 1;
    for(int i=2; i<=n; i++){
        int curr_i = prev+prev2;
        prev2 = prev;
        prev = curr_i;
    }
    cout<<"nth fibbonacci number->>" <<prev<<endl;
    return 0;
}