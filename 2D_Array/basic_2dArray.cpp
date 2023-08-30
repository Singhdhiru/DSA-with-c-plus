#include <iostream>
using namespace std;
int main()
{
    int row, colum;
    cout << "enter the row and colum->";
    cin >> row >> colum;

    // *intialization of 2D  array
    int array[row][colum];

    // *taking 2D array as input->>>> ye colum wise input leta hi
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < colum; j++)
    //     {
    //         cin >> array[i][j];
    //     }
    // }
    // cout << endl;

    // * ye row wise input lega
    for (int i = 0; i < colum; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cin >> array[j][i];
        }
    }
    cout << endl;

    //* print the 2D array
    cout << "print the 2D array->>" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}