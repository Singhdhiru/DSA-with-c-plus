// Reverse integer Q on leetcode
// check the overflow of integer
#include <iostream>
#include <limits.h>
using namespace std;
int getReverseInteger(int n)
{
    int Ans = 0;
    while (n != 0)
    {
        int digit = n % 10;
        if((Ans>(INT_MAX/10))||(Ans<(INT_MIN/10)))
            return 0;
        Ans = (Ans * 10) + digit; // lets assume ans = 2^31-1 hi usme 10 se mlti karne per integer ke range se bahar ho jayega
        n = n / 10;
    }
    return Ans;
}
int main()
{
    int n;
    cout << "enter the number->" << endl;
    cin >> n;
    int ans = getReverseInteger(n);
    cout << "Reverse Number is equal to ->" << ans << endl;
    return 0;
}