// 204. Count Primes
// Given an integer n, return the number of prime numbers that are strictly less than n.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number for checking: ";
    cin >> n;

    int count = 0;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;
            for (int j = 2 * i; j < n; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }
    cout << "total prime exit in the range->" << count << endl;

    return 0;
}

// time complexity->>..>>>>>>>>>>>>O(n*log(log*n))