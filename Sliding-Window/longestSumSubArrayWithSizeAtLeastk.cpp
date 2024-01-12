// https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1
#include <iostream>
#include<limits.h>
using namespace std;

// kadanes Algo+SlidingWindow concept
long long int maxSumWithK(long long int a[], long long int n, long long int k)
{
    long long int i = 0;
    long long int sum = 0;
    long long int mx = LONG_MIN;
    long long int last = 0; // k se extra element add karnge then last ko tarck karenge
    // last add karne per +ve val hota hi add kro nahi toh sub kar denge

    for (int j = 0; j < n; j++)
    {
        sum += a[j];
        if (j - i + 1 == k)
        {
            mx = max(mx, sum);
        }
        else if (j - i + 1 > k)
        {
            mx = max(mx, sum);
            last += a[i];
            i++;
            if (last < 0)
            {
                sum -= last;
                last = 0;
                mx = max(mx, sum);
            }
        }
    }
    return mx;
}
int main()
{
    const int n = 10; // Adjust the size of the array as needed
    long long int a[n] = {1, -2, 3, 4, -5, 6, 7, -8, 9, 10};
    long long int k = 3;

    long long int result = maxSumWithK(a, n, k);

    std::cout << "Maximum sum of subarray with size atleast " << k << " is: " << result << std::endl;

    return 0;
}
