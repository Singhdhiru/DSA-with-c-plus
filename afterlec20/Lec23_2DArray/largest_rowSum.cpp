// * largest sum in array
#include <iostream>
#include <limits.h>
using namespace std;

int largest_sumindex(int array[][4], int row, int colum)
{

    int maxi;
    maxi = INT_MIN;
    int maxiIndex = -1;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += array[i][j];
        }
        if (sum > maxi)
        {
            maxi = sum;
            // * maximum row sum ka index i hi
            maxiIndex = i;
        }
    }
    cout << "the maximum sum is " << maxi << endl;
    return maxiIndex;
}

int main()
{
    int array[3][4];
    cout << "Enter the elements of 2D array: " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> array[i][j];
        }
    }

    cout << "Printing the 2D array: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    int ansIndex = largest_sumindex(array, 3, 4);
    cout << " Max row is at index " << ansIndex << endl;
    return 0;
}
