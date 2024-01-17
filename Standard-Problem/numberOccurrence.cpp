#include <iostream>
using namespace std;

// ? gfg->> https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
// ? hack is->> t.c->>O(logn);
// ?s.c-> O(1);
int firstOccurrence(int arr[], int n, int x)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int lastOccurrence(int arr[], int n, int x)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
bool ispresent(int arr[], int n, int x)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == x)
        {
            return 1;
        }
        else if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return 0;
}
int count(int arr[], int n, int x)
{
    int first = firstOccurrence(arr, n, x);
    int last = lastOccurrence(arr, n, x);
    int countOcc = 0;
    if (ispresent(arr, n, x))
    {
        countOcc = last - first + 1;
    }
    else
    {
        countOcc = 0;
    }
    return countOcc;
}
int main()
{
    int arr[] = {1,1,1,2,2,2,3,3,3,3,3,3,3,3};
    int n = 14;
    int x= 3;
    int ans = count(arr,n,x);
    cout<<"Total number of occurrences->> "<<ans;
    return 0;
}