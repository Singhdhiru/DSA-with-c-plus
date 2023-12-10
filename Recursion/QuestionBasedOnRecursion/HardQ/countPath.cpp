#include <iostream>
using namespace std;

int totalPath(int i, int j, int n, int m){
    // Base case
    // i and j matrix se bahar nikal gaya not possible
    if(i == n || j == m){
        return 0;
    }
    if(i == n-1 && j == m-1){
        return 1;
    }
    // in every step two possible path downword(i = i+1) and rightword(j = j+1)
    return totalPath(i+1, j, n, m)+ totalPath(i, j+1, n, m);
}
int main() {
    int n = 3;
    int m = 4;
    int ans = totalPath(0, 0, n, m);
    cout<<"Total path "<<" "<<ans;
    return 0;
}
// Time complexity - O(2^(m+n)) ->> use dp for reduce time complexity