// find the triplate sum
// this is brute force apoorach and tc = O(n^3)
#include <iostream>
using namespace std;
int Find3sum(int arr[], int n, int target)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (target == arr[i] + arr[j] + arr[k])
                {
                    ans = 1;
                }
            }
        }
    }
    return ans;
}
int main()
{
    int arr[10] = {2, 3, 4, 11, 13, 14, 16};
    int target;
    cout << "enter the target sum " << endl;
    cin >> target;
    cout << "element is present"<< " " << Find3sum(arr, 7, target) << endl;
}