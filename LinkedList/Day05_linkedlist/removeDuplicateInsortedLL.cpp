// * remove duplicate from sorted LL
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // * constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// * insert at head
void insertAtHead(Node *&head, int data)
{
    // * creating new node
    Node *temp = new Node(data);
    // ? point temp ka next is head
    temp->next = head;
    // ? ab temp ko head bna diya
    head = temp;
}

// * insert at tail
void insertAtTail(Node *&tail, int data)
{
    // ? create new node
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

// * insert at position
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{

    // * insert at head
    if (head == NULL || position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    // * agar 3 position per insert karna hi toh to traverse kar ke 2 ko temp bna denge
    int cnt = 1;
    Node *temp = head;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // * insert at tail
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    //*creating a node for data to insert any position
    Node *nodeToInsert = new Node(data);

    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
}
Node *uniqueSortedLL(Node *&head)
{
    // * list is empty
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // * not empty list
    Node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            // * delete  node
            Node *nodeToDelete = curr->next;
            curr->next = curr->next->next;
            delete (nodeToDelete);
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

// ? print the linkedlist
void print(Node *&head)
{
    // ? create new node temp ->> point to the head and traverse
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        // * update the temp
        temp = temp->next;
    }
}
int main()
{
    //? create node with value 10 and null
    Node *node1 = new Node(12);
    cout << "first node->>" << node1->data << endl;

    Node *head = node1;
    Node *tail = node1;
    // * insert at head
    insertAtHead(head, 12);
    insertAtHead(head, 11);
    print(head);

    // ?insert at tail
    insertAtTail(tail, 14);
    print(tail);
    insertAtTail(tail, 15);
    print(tail);
    cout << endl;
    // * insert at given position
    insertAtPosition(head, tail, 6, 33);
    print(head);
    cout << endl;
    uniqueSortedLL(head);
    print(head);
    return 0;
}