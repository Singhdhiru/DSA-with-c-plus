#include <iostream>
#include <math.h>
using namespace std;
int BinaryToDecimal(int n)
{
    int ans = 0;
    int i = 0;
    while (n != 0)
    {
        int digit = n % 10;
        if (digit == 1)
        {
            ans = ans + pow(2, i);
        }
        n = n / 10;
        i++;
    }
    return ans;
}
int main()
{
    int n;
    cout << "enter the number for Binary to Decimal conversion->" << endl;
    cin >> n;
    int Ans = BinaryToDecimal(n);
    cout << "Decimal number->" << Ans << endl;
    return 0;
}
