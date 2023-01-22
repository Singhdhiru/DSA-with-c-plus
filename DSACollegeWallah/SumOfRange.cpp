// Problem 3: Given an array of integers ‘a’ of size n. For q number of inputs,
// print the sum of values in a given
// range of indices from l(starting index for the range) to r(ending index for the range),
// both l and r included in the sum.
// More formally, print a[l] + a[l+1] + a[l+2] + … + a[r] for each q.
// Note: Array ‘a’ follows 1-based indexing i.e. element 1 is at index 1 and not 0, as it usually is.
// Input :5 ->Number of elements in the array a
// 5 1 2 3 4 ->All the elements (space separated)
// outpot : sum from a[1] to a[5], i.e. 5+1+2+3+4=15
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout << "enter the size of vector" << endl;
    cin >> n;
    vector<int> v(n + 1, 0); // 1 base indexing . sare mai 0 se intialize kar ke 1 position se
                             // element push kar denge
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    cout << endl;
    // making a prefix sum array out of given array
    for (int i = 1; i <= n; i++)
    {
        v[i] += v[i - 1];
    }
    int q;                                     // kitna bar alag alag l & r per answer usi ke liye q hi
    cout << "enter the no of queries" << endl; // no of queries
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l;
        cin >> r;
        // ans = prefix_sum[r] - prefix_sum[l-1] uske bich ke sare element ka sum ans hogaa
        int ans = 0;
        ans = v[r] - v[l - 1];
        cout << "ans->" << ans << endl;
    }
}
