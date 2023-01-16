#include <iostream>
#include <math.h>
using namespace std;
int DecimalToBinary(int n)
{
    int ans = 0;
    int i = 0;
    while (n != 0)
    {
        // pahle bit nikalenge
        int bit = (n & 1);
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }
    return ans;
}
int main()
{
    int n;
    cout << "enter the number for binary conversion ->" << endl;
    cin >> n;
    int Ans = DecimalToBinary(n);
    cout << "Binary Number is equal->" << Ans << endl;
    return 0;
}