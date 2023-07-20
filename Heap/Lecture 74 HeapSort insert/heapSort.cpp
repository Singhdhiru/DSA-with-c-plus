#include <iostream>

using namespace std;

// Function to swap two elements in an array.
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Heapify function to maintain heap property.
void heapify(int arr[], int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[largest])
    { // Change "left <= size" to "left < size"
        largest = left;
    }

    if (right < size && arr[right] > arr[largest])
    { // Change "right <= size" to "right < size"
        largest = right;
    }

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, size, largest);
    }
}

// Function to sort an array using Heap Sort.
void heapSort(int arr[], int size)
{
    // Build the max heap first
    for (int i = size / 2 - 1; i >= 0; i--)
    { // Change "i >= 0" to "i >= 0"
        heapify(arr, size, i);
    }

    // Heap sort
    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int size = 5;
    int arr[5] = {4, 1, 3, 9, 7};
    cout << "unsorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // heap creation
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    heapSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
