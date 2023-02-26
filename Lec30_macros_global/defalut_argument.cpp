#include <iostream>
using namespace std;

void print(int arr[], int n, int start = 0) //* defalut hemesa right se left banaya jata hai
{

    for (int i = start; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{

    int arr[5] = {1, 4, 7, 8, 9};
    int size = 5;

    print(arr, size);
    cout << endl;
    print(arr, size, 2); //* agar start = kuch nahi diya jaye toh wo zero se print kar dega

    return 0;
}