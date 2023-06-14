#include <iostream>
using namespace std;

class circularQ
{
    int *arr;
    int size;
    int rear;
    int front;

public:
    circularQ()
    {
        size = 10001;
        arr = new int[size];
        rear = front = -1;
    }

    int  enqueue(int value)
    {
        //?to check whther queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is Full";
        }
        else if (front == -1) //?first element to push
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0; //?to maintain cyclic nature
        }
        else
        { //?normal flow
            rear++;
        }
        //?push inside the queue
        arr[rear] = value;
        cout << "Enqueued element: " << value << endl; //? output the enqueued element
}

    int  dequeue()
    {
        if (front == -1)
        { //? to check queue is empty
            cout << "Queue is Empty " << endl;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        { // ?single element is present
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0; // ?to maintain cyclic nature
        }
        else
        { //? normal flow
            front++;
        }
        return ans;
    }

    int getSize()
    {
        if (front == -1)
        {
            return 0;
        }
        else if (front <= rear)
        {
            return rear - front + 1;
        }
        else
        {
            return size - front + rear + 1;
        }
    }
};
int main()
{
    circularQ q;

    //?enqueue some values
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // ? find the size of the Q
    int ans  = q.getSize();
    cout<<"size of the Q ->> "<<ans<<endl;

    //?dequeue and print the values
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout<<"size of the Q ->> "<<q.getSize()<<endl;
    return 0;
}