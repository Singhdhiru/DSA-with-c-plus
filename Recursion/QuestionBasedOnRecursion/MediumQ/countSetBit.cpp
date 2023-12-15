#include <iostream>
using namespace std;

int CountSetBits(int n)
{
    // base condition
    if (n == 0)
    {
        return 0;
    }
    // If Least significant bit is set
    // last bit 1 ho yani odd number hi
    if ((n & 1) == 1)
        return 1 + CountSetBits(n >> 1);

    // If Least significant bit is not set
    // even ke liye
    else
        return CountSetBits(n >> 1);
}

int main()
{
    int n = 3;
    int ans = CountSetBits(n);
    cout << "total number of set bit-> " << ans << endl;
    return 0;
}