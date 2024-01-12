#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int mod = pow(10, 9) + 7;

// method -> 1 division method->> not use without ask interviewer
// vector<int> getProductArrayexceptItself(int * arr, int n){
//     int product = 1;
//     for(int i=0; i<n; i++){
//         product *= arr[i];
//     }
//     vector<int>ans(n);
//     for(int i=0; i<n; i++){
//         int temp = arr[i];
//         ans.push_back(product/temp);
//     }
//     return ans;
// }

// method ->02 using two arrays
vector<int> getProductArrayExceptSelf(int *arr, int n)
{
    vector<int> l(n), r(n);
    vector<int> result(n);

    l[0] = 1;
    r[n - 1] = 1;

    for (int i = 1; i < n; i++)
    {
        l[i] = (l[i - 1] * arr[i - 1]) % mod;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        r[i] = (r[i + 1] * arr[i + 1]) % mod;
    }

    for (int i = 0; i < n; i++)
    {
        result[i] = (l[i] * r[i]) % mod;
    }

    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> result = getProductArrayExceptSelf(arr, n);
    cout << "Resultant Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
        
    // method ->> division method
    // vector<int> result1 = getProductArrayExceptSelf(arr, n);
    // cout << "Resultant Array: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << result1[i] << " ";
    // }
    
    return 0;
}
