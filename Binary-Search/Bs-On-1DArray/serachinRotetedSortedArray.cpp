#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int> arr, int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}

int binarySearch(vector<int> arr, int s, int e, int k)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

int search(vector<int> &arr, int key)
{
    int n = arr.size();
    int pivot = getPivot(arr, n);

    if (pivot == 0)
    {
        return binarySearch(arr, 0, n - 1, key);
    }

    if (key >= arr[pivot] && key <= arr[n - 1])
    {
        return binarySearch(arr, pivot, n - 1, key);
    }
    else
    {
        return binarySearch(arr, 0, pivot - 1, key);
    }
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int key = 0;
    int result = search(arr, key);
    if (result != -1)
    {
        cout << "Element " << key << " found at index " << result << endl;
    }
    else
    {
        cout << "Element " << key << " not found in the array" << endl;
    }
    return 0;
}
