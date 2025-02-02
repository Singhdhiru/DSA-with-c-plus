// * QuickSort ->> implementation

#include <iostream>
using namespace std;

int partitaion(int arr[], int s, int e)
{
    //* this is heart of quick sort

    int pivot = arr[s]; //* fist element ko pivot maan liya
    int count = 0;      //* ye count karega kinta element small hi pivot se
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivot_index = s + count;
    // * swap pivot element
    swap(arr[pivot_index], arr[s]);

    // * left ans right mai pivot ke codition ko full fill kra dete hi

    int i = s;
    int j = e;
    while (i < pivot_index && j > pivot_index)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] >= pivot)
        {
            j--;
        }
        if (i < pivot_index && j > pivot_index)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivot_index;
}

void quickSort(int arr[], int s, int e)
{
    // * base case
    if (s >= e)
    {
        return;
    }

    // * partition
    int partIndex = partitaion(arr, s, e);

    // * recursive call
    // * left part sort kar do bhai
    quickSort(arr, s, partIndex - 1);
    // * right part sort kar de bhai
    quickSort(arr, partIndex + 1, e);
}
int main()
{
    int arr[] = {78, 90, 99, 88, 4, 56, 34, 33, 45, 6, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    // * print the value
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}