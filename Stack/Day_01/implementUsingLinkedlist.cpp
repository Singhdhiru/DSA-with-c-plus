// #include <iostream>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };
// class Stack
// {
//     Node *head;
//     int capacitiy;
//     int currSize;
//     public:
//     Stack(int maxCapicitiy)
//     {
//         this->capacitiy = maxCapicitiy;
//         this->currSize = 0;
//         head = NULL;
//     }
//     bool isEmpty()
//     {
//         return this->head = NULL;
//     }
//     bool isFull()
//     {
//         return this->currSize == this->capacitiy;
//     }
//     void push(int data)
//     {
//         if(this->currSize == this->capacitiy){
//             cout<<"overflow:"<<endl;
//             return ;
//         }
//         Node* newNode = new Node(data);
//         newNode->next = this->head;
//         this->head = newNode;
//         this->currSize++;
//     }
//     int pop()
//     {
//         if(this->head == NULL){
//             cout<<"underFlow"<<endl;
//             return -1;
//         }
//         Node* newNode = this->head ->next;
//         this->head->next = NULL;
//         Node* tobeRemoved = this->head ;
//         int result = tobeRemoved->data;
//         delete tobeRemoved;
//         this->head = newNode;
//         return result;
//     }
//     int size()
//     {
//         return this->currSize;
//     }
//     int getTop()
//     {
//         if (isEmpty())
//         {
//             cout << "Underflow: Stack is empty." << endl;
//             return -1; // You can choose an appropriate value to return here
//         }
//         return this->head->data;
//     }
// };

// int main()
// {
//     Stack st(6); // 6 is the capacity of the stack
//     st.push(10);
//     st.push(20);
//     cout << "Top element: " << st.getTop() << endl;
//     st.push(30);
//     st.pop();
//     st.push(40);
//     cout << "Top element: " << st.getTop() << endl;

//     return 0;
// }
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
    Node *head;
    int capacity;
    int currSize;

public:
    Stack(int maxCapacity)
    {
        this->capacity = maxCapacity;
        this->currSize = 0;
        head = NULL;
    }

    bool isEmpty()
    {
        return this->head == NULL;
    }

    bool isFull()
    {
        return this->currSize == this->capacity;
    }

    void push(int data)
    {
        if (isFull())
        {
            cout << "Overflow: Stack is full." << endl;
            return;
        }

        Node *newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
        this->currSize++;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Underflow: Stack is empty." << endl;
            return -1;
        }

        Node *toRemove = this->head;
        int result = toRemove->data;
        this->head = this->head->next;
        delete toRemove;
        this->currSize--;
        return result;
    }

    int size()
    {
        return this->currSize;
    }

    int getTop()
    {
        if (isEmpty())
        {
            cout << "Underflow: Stack is empty." << endl;
            return -1;
        }
        return this->head->data;
    }
};

int main()
{
    Stack st(6); // 6 is the capacity of the stack
    st.push(10);
    st.push(20);
    cout << "Top element: " << st.getTop() << endl;
    st.push(30);
    st.pop();
    st.push(40);
    cout << "Top element: " << st.getTop() << endl;

    return 0;
}

