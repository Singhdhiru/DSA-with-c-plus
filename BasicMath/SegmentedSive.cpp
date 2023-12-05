#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

vector<int> primes;
bool isPrime[MAX];

void sieve()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < MAX; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j < MAX; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 2; i < MAX; i++)
        if (isPrime[i])
            primes.push_back(i);
}

void printPrimes(int l, int r)
{
    bool isPrime[r - l + 1];
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 0; primes[i] * primes[i] <= r; i++)
    {
        int curPrime = primes[i];
        int base = (l / curPrime) * curPrime;
        if (base < l)
            base += curPrime;
        for (int j = base; j <= r; j += curPrime)
            isPrime[j - l] = false;
        if (base == curPrime)
            isPrime[base - l] = true;
    }
    for (int i = 0; i <= r - l; i++)
        if (isPrime[i])
            cout << i + l << "\n";
}

int main()
{
    int l, r;
    cout<<"enter the range of High and low->>>";
    cin >> l >> r;
    sieve();
    printPrimes(l, r);
    return 0;
}
