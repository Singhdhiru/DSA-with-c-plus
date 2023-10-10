#include <iostream>
#include <vector>

using namespace std;

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int ans = -1;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                cnt++;
            }
        }
        if (cnt > max)
        {
            max = cnt;
            ans = i;
        }
    }
    return ans;
}

int main()
{
    // Example usage:
    vector<vector<int>> arr = {{0, 1, 1, 1},
                               {0, 0, 1, 1},
                               {1, 1, 1, 1},
                               {0, 0, 0, 0}};
    int n = 4; // Number of rows
    int m = 4; // Number of columns

    int result = rowWithMax1s(arr, n, m);
    cout << "Row with the maximum number of 1s is: " << result << endl;

    return 0;
}
