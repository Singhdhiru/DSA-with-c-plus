#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int size, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < size && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right < size && arr[smallest] > arr[right])
    {
        smallest = right;
    }
    if (smallest != index)
    {
        swap(arr[smallest], arr[index]);
        heapify(arr, size, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
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

    vector<int> minHeap = buildMinHeap(arr);

    cout << "Min Heap: ";
    for (int num : minHeap)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
