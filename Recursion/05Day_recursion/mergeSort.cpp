// * merge two sorted array
#include <iostream>
using namespace std;
void mergeSortedArray(int arr1[], int n1, int arr2[], int n2, int arr3[])
{
    int i = 0; // Pointer for arr1
    int j = 0; // Pointer for arr2
    int k = 0; // Pointer for arr3

    // Iterate over both arrays and add the smaller value to arr3
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }

    // If there are remaining elements in arr1, add them to arr3
    while (i < n1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    // If there are remaining elements in arr2, add them to arr3
    while (j < n2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
}
int main()
{
    int arr1[] = {23, 45, 67, 89, 90};
    int arr2[] = {12, 23, 34, 56, 78, 89, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int n3 = n1 + n2;
    int arr3[n3];
    mergeSortedArray(arr1, n1, arr2, n2, arr3);
    for (int i = 0; i < n3; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
    return 0;
}
// * important artical->>https://www.geeksforgeeks.org/merge-sort/
