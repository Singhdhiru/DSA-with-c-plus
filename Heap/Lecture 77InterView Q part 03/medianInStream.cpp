#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> findMedian(vector<int> &arr, int n) {
    vector<int> medians; // Vector to store the medians for each step

    priority_queue<int> maxheap; // Max-heap to store lower half elements
    priority_queue<int, vector<int>, greater<int>> minheap; // Min-heap to store upper half elements

    for (int i = 0; i < n; ++i) {
        int x = arr[i];

        // Step 1: Insert the element into the appropriate heap
        if (maxheap.empty() || x <= maxheap.top()) {
            maxheap.push(x);
        } else {
            minheap.push(x);
        }

        // Step 2: Balance the heaps if necessary
        if (maxheap.size() > minheap.size() + 1) {
            int t = maxheap.top();
            maxheap.pop();
            minheap.push(t);
        } else if (maxheap.size() < minheap.size()) {
            int t = minheap.top();
            minheap.pop();
            maxheap.push(t);
        }

        // Step 3: Calculate the current median and add it to the medians vector
        if (i % 2 == 0) {
            // If the number of elements seen so far is odd, median is the top of maxheap
            medians.push_back(maxheap.top());
        } else {
            // If the number of elements seen so far is even, median is the average of top elements from both heaps
            int median = (maxheap.top() + minheap.top()) / 2;
            medians.push_back(median);
        }
    }

    return medians;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> medians = findMedian(arr, n);

    cout << "Medians at each step:\n";
    for (int median : medians) {
        cout << median << " ";
    }
    cout << endl;

    return 0;
}
