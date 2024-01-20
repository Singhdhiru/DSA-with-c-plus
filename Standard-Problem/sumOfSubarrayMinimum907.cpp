#include <bits/stdc++.h>
using namespace std;

vector<int> getNSL(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            // left side se ja rahe hi yani first element ke left mai kuch
            // nahi hi isliye -1 add kr lo res mai ye idx store kr raha hi
            res[i] = -1;
        }
        else
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            { // stricktly less
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
        }
        st.push(i);
    }
    return res;
}
vector<int> getNSR(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            // agar first element hi toh n hi push kr dokyuki uske right mai
            // ->>right size se aa rahe hi kuch nahi hi ye idx store kr raha
            // rah hi n ki value
            res[i] = n;
        }
        else
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            { // non-strictly less->> kyuki element repeat nahi honge
                st.pop();
            }
            res[i] = st.empty() ? n : st.top();
        }
        st.push(i);
    }
    return res;
}
int sumSubarrayMins(int N, vector<int> &arr)
{

    vector<int> NSL = getNSL(arr); // Next smaller to left
    vector<int> NSR = getNSR(arr); // Next smaller to right

    long long sum = 0;
    int M = 1e9 + 7;
    for (int i = 0; i < N; i++)
    {
        long long d1 = i - NSL[i]; // distance to nearest smaller to left from i

        long long d2 = NSR[i] - i; // distance to nearest smaller to right from i

        /*
            we have d1 numbers in the left and d2 numbers in the right
            i.e. We have d1 options to start from the left of arr[i]
            and d2 options to end in the right of arr[i]
            so the total options to start and end are d1*d2
        */
        long long total_ways_for_i_min = d1 * d2;
        long long sum_i_in_total_ways = arr[i] * (total_ways_for_i_min);

        sum = (sum + sum_i_in_total_ways) % M;
    }
    return sum;
}
int main()
{
    int N = 4; // replace with the desired size of the array
    vector<int> arr = {3, 1, 2, 4}; // replace with your array values
    int result = sumSubarrayMins(N, arr);

    // Output the result
    cout << "Result: " << result << endl;

    return 0;
    return 0;
}