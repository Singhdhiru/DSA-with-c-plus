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

// * reverse by k groups linkedlist
// Node *reverseK(Node *&head, int k)
// {
//     Node* pre = NULL;
//     Node* curr = head;
//     Node* nextPtr = NULL;
//     int count = 0;
//     while(curr != NULL || count < k){
//         curr -> next = pre;
//         nextPtr->next = curr;
//         pre = curr;
//         curr = nextPtr;
//         count++;
//     }
//     if(nextPtr != NULL){
//         head->next = reverseK(nextPtr,k);
//     }
//     return pre;
// }
Node* reverseK(Node*& head, int k) {
    Node* pre = NULL;
    Node* curr = head;
    Node* nextPtr = NULL;
    int count = 0;

    // *Reverse first k nodes of the linked list
    while (curr != NULL && count < k) {
        nextPtr = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nextPtr;
        count++;
    }

    // *Recursively call for the remaining part of the linked list
    if (nextPtr != NULL) {
        head->next = reverseK(nextPtr, k);
    }

    // *Update the head pointer to point to the new head of the reversed list
    head = pre;
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
    Node *node1 = new Node(10);

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
    insertAtPosition(head, tail, 1, 33);
    print(head);
    cout<<endl;
    cout<<"reverse by k group-->>"<<endl;
    // * reverse by k groups
    Node *newNode = reverseK(head, 2);
    print(newNode);
    return 0;
}