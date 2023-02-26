// * find a^b!
#include <iostream>
using namespace std;

int power(int a, int b)
{
    // * base case
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    // * recursive call
    int Ans = power(a, b / 2);
    if (b % 2 == 0)//* if b is even
    {
        return Ans * Ans;
    }
    else
    {
        //* if b is odd
        return a * Ans * Ans;
    }
}
int main()
{
    int a, b;
    cout << "enter the a and b ->>";
    cin >> a >> b;
    int ans = power(a, b);
    cout << ans << endl;
    return 0;
}