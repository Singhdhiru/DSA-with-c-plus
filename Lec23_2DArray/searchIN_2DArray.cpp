//  * search in 2D array
// #include <iostream>
// using namespace std;

// * time complexity->>>>O(row*colum)
// bool isFound(int array[][4], int target, int row, int colum)
// {
//     *traverse all element of 2D array
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < colum; j++)
//         {
//             if (array[i][j] == target)
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// }
// int main()
// {
//      int row, colum;
//      cout << "enter the row and colum->";
//     cin >> row >> colum;

//     *intialization of 2D  array
//     int array[3][4];
//     cout<<"enter the element of 2D array->>>"<<endl;
//     * ye row wise input lega
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             cin >> array[j][i];
//         }
//     }
//     cout << endl;

//     //* print the 2D array
//     cout << "print the 2D array->>" << endl;
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             cout << array[i][j] << " ";
//         }
//         cout << endl;
//     }

//     int target;
//     cout << "enter the target->>>";
//     cin >> target;

//     if (isFound(array, target, 3, 4))
//     {
//         cout << "element is present" << endl;
//     }
//     else
//     {
//         cout << "element is not present" << endl;
//     }
//     return 0;
// }
#include <iostream>
using namespace std;

bool isFound(int array[][4], int target, int row, int colum)
{
    // traverse all elements of 2D array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            if (array[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
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

    int target;
    cout << "Enter the target: ";
    cin >> target;

    if (isFound(array, target, 3, 4))
    {
        cout << "The element is present." << endl;
    }
    else
    {
        cout << "The element is not present." << endl;
    }
    return 0;
}