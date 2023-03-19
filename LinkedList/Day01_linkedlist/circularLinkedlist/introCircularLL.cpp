#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // * constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // * destructor
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data " << val << endl;
    }
};

// * insert data
// void insertNode(Node *&tail, int element, int data)
// {
//     // * if linkedlist is empty
//     if (tail == NULL)
//     {
//         Node *newNode = new Node(data);
//         tail = newNode;
//         newNode->next = newNode;
//     }
//     else
//     {
//         // * LL is not empty
//         //?assuming that the element is present in the list
//         Node *curr = tail;
//         while (curr->data != element)
//         { //* jab tak element nahi mil jata curr ko aage badate rahenge
//             curr->next = curr;
//         }

//         //?element found -> curr is representing element wala node
//         Node *temp = new Node(data);
//         temp->next = curr->next;
//         curr->next = temp;
//     }
// }

void insertNode(Node *&tail, int element, int d)
{

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        // assuming that the element is present in the list

        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found -> curr is representing element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
// * print circular linkedlist
void print(Node *&tail)
{
    Node *temp = tail;

    //? empty list
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

void deleteNode(Node *&tail, int value)
{
    // * empty list
    if (tail == NULL)
    {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else
    {
        // *non-empty

        // *assuming that "value" is present in the Linked List

        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // ?1 Node Linked List
        if (curr == prev)
        {
            tail = NULL;
        }

        // ? >=2 Node linked list
        else if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 3, 4);
    print(tail);
    insertNode(tail, 4, 5);
    print(tail);
    insertNode(tail, 5, 6);
    print(tail);
    deleteNode(tail, 6);
    print(tail);
    return 0;
}