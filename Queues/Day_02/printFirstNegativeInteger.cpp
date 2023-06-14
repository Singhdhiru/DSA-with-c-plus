#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long A[], long long int n, long long int k)
{
    deque<long long int> dq;
    vector<long long> ans;
    int negative = -1;

    // ? process first window
    for (int i = 0; i < k; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }
    // ? push ans for first window
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // ?  now processing foe reamaining window
    for (int i = k; i < n; i++)
    {
        // ? first pop out of window element
        if (!dq.empty() && (i - dq.front()) >= k)
        {
            dq.pop_front();
        }

        // ? then push current element
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
        // ? put in ans
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}
int main()
{
    // example input arrays
    long long arr1[] = {2, -5, -6, 0, -8, 7, -9};
    long long k1 = 3;
    long long n1 = sizeof(arr1)/sizeof(arr1[0]);
    
    long long arr2[] = {1, 2, 3, 4, 5};
    long long k2 = 3;
    long long n2 = sizeof(arr2)/sizeof(arr2[0]);
    
    // call printFirstNegativeInteger function for first array
    vector<long long> ans1 = printFirstNegativeInteger(arr1, n1, k1);

    // print result
    cout << "Result for arr1: ";
    for (long long i : ans1) {
        cout << i << " ";
    }
    cout << endl;
    
    // call printFirstNegativeInteger function for second array
    vector<long long> ans2 = printFirstNegativeInteger(arr2, n2, k2);

    // print result
    cout << "Result for arr2: ";
    for (long long i : ans2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}