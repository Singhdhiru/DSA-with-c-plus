#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> arr, int N)
{
    unordered_map<int, int> m;

    int sum = 0;
    int max_len = 0;

    for (int i = 0; i < N; i++)
    {

        sum += arr[i];
        if (sum == 0)
            max_len = i + 1;

        if (m.find(sum) != m.end())
        {
            max_len = max(max_len, i - m[sum]);
        }
        else
        {
            m[sum] = i;
        }
    }
    return max_len;
}

int main()
{
    int n;

    cout << "Enter the size = ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements = ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\nThe length of the longest 0 sum subarray = " << maxLen(a, n);

    return 0;
}