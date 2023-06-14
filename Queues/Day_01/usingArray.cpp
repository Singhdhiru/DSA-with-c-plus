#include <iostream>
#include <queue>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    // ? constructor
    Queue()
    {
        size = 10001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // ? Public Functions of Queue

    bool isEmpty()
    {
        if (rear == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "queue is full " << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }
    int getfront()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};
int main()
{
    Queue q;

    // Enqueue some elements
    q.enqueue(11);
    q.enqueue(15);
    q.enqueue(13);

    // Print the front element
    cout << "Front of queue: " << q.getfront() << endl;

    // Dequeue some elements
    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;

    // Check if the queue is empty
    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}