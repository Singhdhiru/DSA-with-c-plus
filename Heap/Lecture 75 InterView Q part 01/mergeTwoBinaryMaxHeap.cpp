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
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // merge to array
    // step->>> 01
    vector<int> ans;
    for (auto i : a)
    {
        ans.push_back(i);
    }
    for (auto i : b)
    {
        ans.push_back(i);
    }

    int size = ans.size();
    // step ->> 02 make heap from merge array ->>> aplly heapify algorithm
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(ans, size, i);
    }
    return ans;
}

int main()
{
    // Test the mergeHeaps function
    vector<int> a = {3, 8, 10};
    vector<int> b = {6, 7, 9};
    int n = a.size();
    int m = b.size();

    vector<int> mergedHeap = mergeHeaps(a, b, n, m);

    cout << "Merged Heap: ";
    for (int val : mergedHeap)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}