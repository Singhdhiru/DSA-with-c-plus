// implementation of selection sort
// time complexity-> O(n^2)
// space complexity
#include <iostream>
using namespace std;
void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[minindex])
            {
                minindex = j;
            }
            // swap the  value
            int temp = arr[j];
            arr[j] = arr[minindex];
            arr[minindex] = temp;
        }
    }
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "enter the size of array" << endl;
    cin >> n;
    // take input array from the user
    int arr[6];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SelectionSort(arr, n);
    cout << "print the array after the sorting" << endl;
    printarray(arr, n);
    return 0;
}