// recursion to memoization conversion

// ? recursion code
// #include <iostream>
// using namespace std;
// int fib(int n){
    // base case 
//     if(n<=1){
//         return n;
//     }
//     return fib(n-1)+fib(n-2);
// }
// int main() {
//     int n = 5;
//     cout<<fib(n)<<endl;
//     return 0;
// }

// ? dynamic programming code
// using memoizaton methods(top-down apporaches)
#include <iostream>
#include<vector>
using namespace std;

int fib(int n, vector<int>& dp){
    if(n<=1){
        return n;
    }
    // step -02
    if(dp[n] != -1){
        return dp[n];
    }
    // step -03
    return dp[n] = fib(n-1, dp)+fib(n-2, dp);
}
int main() {
    int n = 5;
    // step -01 declear array
    vector<int>dp(n+1, -1);
    cout<<"fiboonachi number-> "<<fib(n, dp)<<endl;
    return 0;
}