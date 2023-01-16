// check number is prime or not
// Prime numbers are natural numbers that are divisible by only 1 and the number itself.
//  example-> 2,3,5,7,11,13,17,19,23 ...........
#include <iostream>
using namespace std;
int main()
{
    int i = 2, n;
    cout << "enter number" << endl;
    cin >> n;
    while (i < n) // loop ko n-1 times chalana hi agar n times chalayenge to n ko n se divide karne per hamesa hi prime hoha
    {
        if (n % i == 0)
        {
            cout << "print n is not prime numer for " << i << endl;
        }
        else
        {
            cout << "print n is prime number for " << i << endl;
        }
        i = i + 1;
    }
}