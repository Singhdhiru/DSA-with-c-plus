// *row and colum wise sum in 2D array
#include<iostream>
using namespace std;

void row_wiseSum(int array[][4], int row, int colum){

    // * row wise sum keliye pahle row ko traverse karna padega

    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += array[i][j];
        }
        cout<<sum<<" ";
    }
    cout<<endl;

}

int colum_wiseSum(int array[][4], int row, int colum){

    // * colum wise sum keliye pahle colum ko traverse karna padega
    for (int i = 0; i < 4; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += array[j][i];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

int main(){
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

    cout<<"print the row wise sum->>";
    row_wiseSum(array, 3, 4);
    cout<<endl;

    cout<<"print the colum wise sum->>>";
    colum_wiseSum(array, 3, 4);
    return 0;
}