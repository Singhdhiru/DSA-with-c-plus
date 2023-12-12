// Friends pairing problem

#include <iostream>
using namespace std;

int totalWays(int n){
    // base case ->> 1 friend ko invite karne and less 0 ka bhi 1 hoga
    if(n <= 1){
        return 1;
    }
    // single
    int ways1 = totalWays(n-1);
    // pairwise
    int ways2 = (n-1)*totalWays(n-2);
    return ways1+ways2;
}
int main() {
    int n =4;
    cout<<" Total number of Ways to invite friends->> "<<totalWays(n)<<endl;
    return 0;
}