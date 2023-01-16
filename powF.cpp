// find power of number using funcion.
#include <iostream>
using namespace std;
int power(int a, int b)
{ // user define function
    cout << "entre two number a and b" << endl;
    cin >> a >> b;
    int ans = 1;
    for (int i = 1; i <= b; i++)
    {
        ans = ans * a;
    }
    return ans;
}
int main()
{ // predefine function
    int a, b;
    // int ans = power(a,b);
    // cout<<"pow is ="<<ans<<endl;
    cout << power(a, b) << endl;
    cout << power(a, b) << endl;
    cout << power(a, b) << endl;
}
