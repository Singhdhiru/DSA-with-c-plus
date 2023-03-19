// * no node present in first
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *pre;
    Node *next;
    // * constructor
    Node(int d)
    {
        this->data = d;
        this->pre = NULL;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// * insert at head in doubly linkedlist
void insertAtHead(Node* &tail, Node *&head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
}

// * insert at tail
void insertAtTail(Node *&tail, Node* &head,  int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->pre = tail;
        tail = temp;
    }
}

// ? insert at any position
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // * insert at head
    if (position == 1 || head == NULL)
    {
        insertAtHead(tail, head, data);
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
        insertAtTail(tail, head,  data);
        return;
    }

    //*creating a node for data to insert any position
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->pre = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->pre = temp;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    // * insert at head
    insertAtHead(tail, head, 9);
    print(head);
    insertAtHead(tail, head, 8);
    print(head);
    insertAtHead(tail, head, 7);
    print(head);

    // * insert at Tail
    insertAtTail(tail, head,  11);
    print(head);
    insertAtTail(tail, head,  12);
    print(head);
    insertAtTail(tail, head,  13);
    print(head);

    // * insert at any position
    insertAtPosition(head, tail, 1, 6);
    print(head);
    insertAtPosition(head, tail, 8, 101);
    print(head);
    insertAtPosition(head, tail, 6, 100);
    print(head);

    return 0;
}