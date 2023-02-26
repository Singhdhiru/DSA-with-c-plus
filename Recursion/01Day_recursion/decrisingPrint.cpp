//* print n to 1 & print 1 to n

#include <iostream>
using namespace std;

void decrising_print(int n)
{

    //* base case
    if (n == 0)
        return;

    cout << n << endl; //* processing

    decrising_print(n - 1); //* R.R
}

void incresing_print(int n)
{
    //* base case
    if (n == 0)
        return;
    //* R.R
    incresing_print(n - 1);
    //* processing
    cout << n << endl;
}

int main()
{
    int n;
    cout << "enter the number->>";
    cin >> n;
    decrising_print(n);
    cout << endl;
    incresing_print(n);
    return 0;
}