#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> factorial(int N)
{
    vector<int> ans(1, 1);
    while (N > 1)
    {
        int carry = 0;
        int size = ans.size();
        int res;
        for (int i = 0; i < size; i++)
        {
            res = ans[i] * N + carry;
            ans[i] = res % 10;
            carry = res / 10;
        }
        while (carry)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
        }
        N--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    // Example: Calculate factorial of 5
    int N = 59;
    vector<int> result = factorial(N);

    // Display the result
    cout << "Factorial of " << N << " is: ";
    for (int digit : result)
    {
        cout << digit;
    }
    cout << endl;

    return 0;
}
