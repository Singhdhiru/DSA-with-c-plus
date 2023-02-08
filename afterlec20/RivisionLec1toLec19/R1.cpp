#include <iostream>
using namespace std;
int SubtractProductAndSum(int number)
{
    int product = 1;
    int sum = 0;
    while (number != 0)
    {
        product = product * (number % 10);
        sum = sum + (number % 10);
        number = number / 10;
    }
    int ans = product - sum;
    return ans;
}
int main()
{
    int number;
    // cout << "enter the number" << endl;
    // cin >> number;
    int Ans =SubtractProductAndSum(123);    
    cout << "subtraction of product and sum is->" << Ans << endl;
    return 0;
}