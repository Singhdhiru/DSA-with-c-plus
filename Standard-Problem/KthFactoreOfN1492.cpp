#include <iostream>
using namespace std;

// ? 1492. The kth Factor of n
int kthFactor(int n, int k)
{
    int d = 1;
    for (; d * d <= n; d++)
    {
        if (n % d == 0 && --k == 0)
        {
            return d;
        }
    }
    for (d = d - 1; d >= 1; d--)
    {
        if (d * d == n)
        {
            continue;
        }
        if (n % d == 0 && --k == 0)
        {
            return n / d;
        }
    }
    return -1;
}

int main() {
    int n, k;

    // Input values for n and k
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Enter the value of k: ";
    cin >> k;

    // Call the kthFactor function and print the result
    int result = kthFactor(n, k);

    if (result != -1) {
        cout << "The " << k << "th factor of " << n << " is: " << result << endl;
    } else {
        cout << "There is no " << k << "th factor of " << n << endl;
    }

    return 0;
}