// * find factorial of number using recursion
#include <iostream>
using namespace std;

int factorial(int n)
{

    //* base caase
    if (n == 0)
    {
        return 1;
    }
    //* recursive relation
    return n * factorial(n - 1);
}
int main()
{
    int n;
    cout << "enter the number->>";
    cin >> n;
    int ans = factorial(n);
    cout << ans << endl;
    return 0;
}