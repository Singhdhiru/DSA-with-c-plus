// * important question based on merge sort ->> inversion count
#include <iostream>
using namespace std;

int merge(int *arr, int s, int e)
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

    int inversionCount = 0;

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
            // *calculate inversion count
            inversionCount += (mid - s + 1 - index1); //*--->>>> important line
            // inversionCount += (mid - index1); //*--->>>> important line
        }
    }

    // * agar 1st array mai element bach gaye
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    // * agar 2nd array mai element bach gaye
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    // *jo sub array banaya hi usko delete karna padega
    delete[] first;
    delete[] second;
    return inversionCount ;
    
}


int mergeSort(int arr[], int s, int e)
{
    // * base case
    if (s >= e)
    {
        return 0;
    }
    int mid = s + (e - s) / 2;

    int inversionCount = 0;

    // * left part ka inversion
    inversionCount += mergeSort(arr, s, mid);

    // * right part ka inversion count
    inversionCount += mergeSort(arr, mid + 1, e);

    // * merge karte time ka inversion
    inversionCount += merge(arr, s, e);

    return inversionCount;
}
int main()
{
    int arr[] = {5, 3, 2, 1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = mergeSort(arr, 0, n);
    cout << "The total inversions are " << ans << endl;
    return 0;
}
