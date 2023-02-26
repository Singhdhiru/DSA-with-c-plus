#include<iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    // * lenght of 1st subarray
    int len1 = mid - s + 1;
    // * lenght of second subarray
    int len2 = e - mid;

    // * create two subarray with lenght  len1  ans len2->> dynamically array
    int *first = new int[len1];
    int *second = new int[len2];

    // * copy  the value in two sub array
    int mainArrayIndex = s; //* main array ka index jaha se value 1st subarray  mai dalna hi
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex];
        mainArrayIndex++; //* index lo aage bhi badhana hi
    }

     mainArrayIndex = mid + 1; //* main array ka index jaha se value 2nd subarray  mai dalna hi
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex];
        mainArrayIndex++;
    }

    //* mergeSorted array
    int index1 = 0;     //* index of first sub array
    int index2 = 0;     //* index of second sub array
    mainArrayIndex = s; //* index of main array

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // * agar 1st array mai element bach gaye
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    // * agar 1st array mai element bach gaye
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    // *jo sub array banaya hi usko delete karna padega
    delete[] first;
    delete[] second;
}
void mergeSort(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    //* base case
    if (s >= e)
    {
        return;
    }
    //* left part mai jaoo
    mergeSort(arr, s, mid);
    //*right part mai jaoo
    mergeSort(arr, mid + 1, e);

    // * merge two array
    merge(arr, s, e);
}
int main()
{
    int arr[10] = {90, 89, 45, 67, 78, 33, 1, 34, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}