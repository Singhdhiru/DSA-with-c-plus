#include <iostream>
using namespace std;

int placeTiles(int n, int m){
    // base case
    if(n<m){
        return 1;
    }
    if(n == m){
        return 2;
    }
    // vertically
    int verticallyPlace = placeTiles(n-m, m);
    // horizontally
    int horizontallyPalce = placeTiles(n-1, m);

    return verticallyPlace+horizontallyPalce;
}
int main() {
    int n = 4;
    int m = 2;
    cout<<"no of ways to place tiles"<<" "<<placeTiles(n,m)<<endl;
    return 0;
}
// use dp to reduce time t.E