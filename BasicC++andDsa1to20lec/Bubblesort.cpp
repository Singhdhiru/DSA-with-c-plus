// implementation of bubble sort
// time complexity (b.s) = O(n) array already sorted
// time complexity (w.s) = O(n^2) array reverse sorted
// space complexity= O(1);

#include <iostream>
using namespace std;
/* Brute force technique
void BubbleSort(int arr[] , int n ){
 for(int i = 0 ; i< n ; i++){
    for(int j = 0 ; j < n; j++){
        if(arr[j]> arr[j+1]){
        int  temm = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp ;
        }
    }
 }
}*/
// optimize code
void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapp = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapp = true;
            }
        }
        if (swapp == false)
        {
            // element is already sorted
            break;
        }
    }
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "enter the size of array" << endl;
    cin >> n;
    // take input array from the user
    int arr[10];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    BubbleSort(arr, n);
    // cout<<"print the array after the sorting"<<endl;
    printarray(arr, n);
    return 0;
}