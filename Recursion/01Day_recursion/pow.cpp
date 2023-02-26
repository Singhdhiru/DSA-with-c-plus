#include <iostream>
using namespace std;

// * find 2^n
int pow(int n)
{
    if (n == 0)
    { //* base case
        return 1;
    }
    //* recursive relation
    return 2 * pow(n - 1);
}
int main()
{

    int n;
    cout << "enter the number-->>";
    cin >> n;
    int ans = pow(n);
    cout<<ans<<endl;

}