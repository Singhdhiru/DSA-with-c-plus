// time complexity->o(n^2)->reduce 
#include <iostream>
using namespace std;

bool check_prime(int n)
{

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cout << "Enter the number for checking: ";
    cin >> n;

    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (check_prime(i))
        {
            count++;
        }
    }

    cout << "Total number of prime numbers up to " << n << " is " << count << endl;
    return 0;
}
