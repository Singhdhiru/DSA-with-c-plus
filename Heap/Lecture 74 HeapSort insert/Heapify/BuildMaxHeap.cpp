#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < size && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
}

vector<int> buildMaxHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    return arr;
}

int main()
{
    vector<int> arr = {4, 10, 3, 5, 1};
    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> maxHeap = buildMaxHeap(arr);

    cout << "MAX Heap: ";
    for (int num : maxHeap)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
