// find the tripalte sum of given array
// optimize solution of 3Sum
// time complexity = O(n^2)
#include <iostream>
using namespace std;
bool Find3Sum(int arr[], int n, int target)
{

    for (int i = 0; i < n; i++)
    {
        int y = target - arr[i];
        int low = i + 1;
        int high = n - 1;
        while (low < high)
        {
            if (arr[low] + arr[high] == y)
            {
                return true;
            }
            else if (arr[low] + arr[high] > y)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
    }
    return false;
}
int main()
{
    int arr[6] = {23, 45, 76, 89, 90, 100}; // sorted array is given
    int target;
    cout << "enter the target" << endl;
    cin >> target;
    int ans = Find3Sum(arr, 6, target);
    cout << "if present return 1 and else return 0 :" << " " << ans << endl;
}