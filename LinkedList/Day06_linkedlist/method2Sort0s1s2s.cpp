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

Node *sort0s1s2s(Node *&head)
{
    // ?create dummy
    Node *zeroHead = new Node(-1);
    Node *zerotail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *onetail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;
    // ?create seprate list 0s 1s 2s
    while (curr != NULL)
    {
        int value = curr->data;
        if (value == 0)
        {
            insertAtTail(zerotail, value);
        }
        else if (value == 1)
        {
            insertAtTail(onetail, value);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail, value);
        }
        curr = curr->next;
    }
    //? merge three sublist

    // ?1st list is not empty
    if (oneHead->next != NULL)
    {
        zerotail->next = oneHead->next;
    }
    else
    {
        //* 1st list is empty
        zerotail->next = twoHead->next;
    }
    onetail->next = twoHead->next;
    twoTail->next = NULL;

    //? setupHead
    head = zeroHead->next;
    // *delete all dummy node
    delete zeroHead;
    delete oneHead;
    delete twoHead;
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
    Node *node1 = new Node(0);
    cout << "first node->>" << node1->data << endl;

    Node *head = node1;
    Node *tail = node1;

    // * insert at head
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);

    // ?insert at tail
    insertAtTail(tail, 2);
    print(tail);
    insertAtTail(tail, 0);
    print(tail);
    cout << endl;
    // * insert at given position
    insertAtPosition(head, tail, 1, 0);
    print(head);
    cout<<endl;
    cout << "print LL is sorted in 0s 1s & 2s->>" << endl;
    Node* temp = sort0s1s2s(head);
    print(temp);
    return 0;
}