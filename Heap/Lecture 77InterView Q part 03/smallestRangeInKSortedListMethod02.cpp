#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int kSorted(vector<vector<int>> &arr, int k, int n) // Fix the function signature
{
    vector<int> pointer(k, 0);
    int ans = INT_MAX;
    while (true)
    {
        // Step 2:
        int mini = 0;
        int maxi = 0;
        for (int i = 0; i < k; i++)
        {
            if (arr[mini][pointer[mini]] > arr[i][pointer[i]])
                mini = i;
            if (arr[maxi][pointer[maxi]] < arr[i][pointer[i]])
                maxi = i;
        }
        // Step 3:
        ans = min(ans, (arr[maxi][pointer[maxi]] - arr[mini][pointer[mini]]) + 1);
        // Step 4:
        if (pointer[mini] + 1 < n)
        {
            pointer[mini]++;
        }
        else
            break;
    }
    return ans;
}

int main()
{
    vector<vector<int>> KSortedArray = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };
    int n = 5; // Number of columns
    int k = 3; // Number of rows

    int result = kSorted(KSortedArray, k, n); // Correct the order of arguments
    cout << "Smallest Range: " << result << endl;

    return 0;
}
