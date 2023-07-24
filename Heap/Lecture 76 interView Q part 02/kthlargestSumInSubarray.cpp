#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> mini;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j]; // Fix: Changed arr[i] to arr[j]
            if (mini.size() < k)
            {
                mini.push(sum);
            }
            else
            {
                if (sum > mini.top())
                {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}

int main()
{
    vector<int> arr = {3, 1, 5};
    int k = 3;

    int kthLargest = getKthLargest(arr, k);

    cout << "The " << k << "th largest sum of subarrays is: " << kthLargest << endl;

    return 0;
}
