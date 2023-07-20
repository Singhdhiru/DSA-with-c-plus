#include <iostream>
#include <queue>
using namespace std;
int main()
{

    // max heap creation using stl
    priority_queue<int> pq;
    pq.push(2);
    pq.push(5);
    pq.push(7);
    pq.push(6);
    pq.push(10);
    cout << "top element in heap: " << pq.top() << endl;
    cout << "size of heap: " << pq.size() << endl;
    pq.pop();
    cout << "top element in heap: " << pq.top() << endl;
    cout << "size of heap: " << pq.size() << endl;

    // min heap creation
    // Creates a min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(5);
    minHeap.push(1);
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);

    // One by one extract items from min heap
    cout<<"print Min Heap : ";
    while (minHeap.empty() == false)
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    return 0;
}
