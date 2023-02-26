// * bubble sort using recursion
#include <iostream>
using namespace std;

void sortArray(int *arr, int size)
{
    // * base case -> array is already sorted
    if (size == 0 || size == 1)
    {
        return;
    }
    //*1 case sovle karlia - largest element ko end me rakh dega
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    //*Recursive Call
    sortArray(arr, size - 1);
}
int main()
{
    int arr[6] = {12, 2, 4, 89, 90, 2};
    int size = 6;
    sortArray(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}