#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src, char helper, char dest)
{
    // base case
    if (n == 1)
    { // jab src per 1 hi hi toh src to des per rakh do
        cout << "Transfer Disk " << n <<" "<< "from" << " "<<src  << " To" <<" "<< dest<<endl;
        return;
    }
    // recursive call
    // transfer top n-1 from src to helper using dest as 'helper'
    towerOfHanoi(n - 1, src, dest, helper);
    // transfer nth from src to dest
    cout<<"Transfer disk"<<n<<" "<<"from"<<" "<<src<<"to"<<" "<<helper<<endl;
    // transfer n-1 from helper to dest using src as 'helper'
    towerOfHanoi(n - 1, helper, src, dest);
}
int main()
{
    int n = 2;
    towerOfHanoi(n, 'S', 'H', 'D');
    return 0;
}