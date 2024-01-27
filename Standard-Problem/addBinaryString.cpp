#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

string addBinary(string a, string b)
{
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    string ans;

    while (i >= 0 and j >= 0)
    {

        if ((a[i] == '1' and b[j] == '0') or (a[i] == '0' and b[j] == '1'))
        {
            if (carry)
                ans += '0';
            else
                ans += '1';
        }
        else if (a[i] == '1' and b[j] == '1')
        {
            if (carry)
                ans += '1';
            else
                ans += '0', carry = 1;
        }
        else if (a[i] == '0' and b[j] == '0')
        {
            if (carry)
                ans += '1', carry = 0;
            else
                ans += '0';
        }

        i--, j--;
    }
    //   jab a mai abhi bhi kuch element bach gaya hi
    while (i >= 0)
    {
        if (a[i] == '1')
        {
            if (carry)
                ans += '0';
            else
                ans += '1';
        }
        else
        {
            if (carry)
                ans += '1', carry = 0;
            else
                ans += '0';
        }
        i--;
    }
    //   b mai abh  bhi kuch element bach gaya hi
    while (j >= 0)
    {
        if (b[j] == '1')
        {
            if (carry)
                ans += '0';
            else
                ans += '1';
        }
        else
        {
            if (carry)
                ans += '1', carry = 0;
            else
                ans += '0';
        }
        j--;
    }
    //   last mai ho sakta hi 1 carry ho
    // example->> 11 + 11
    if (carry)
        ans += '1', carry = 0;
    //   ans ko reverse karna hoga
    reverse(ans.begin(), ans.end());
    //   leading zero hatana hi->> ans->>> 001101->> 2 zero ko hta do
    int k = 0;
    while (k < ans.size() and ans[k] == '0' and ans.size() != 1)
        k++;

    return ans.substr(k, ans.size());
}
int main()
{
     // Example usage
    string result = addBinary("101", "110");
    cout << "Result: " << result << endl;

    return 0;
}