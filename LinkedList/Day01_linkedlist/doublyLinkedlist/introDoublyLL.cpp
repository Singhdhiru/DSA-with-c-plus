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

    ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

// * find the lenght of linked list;
int getLenght(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
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
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head->pre = temp;
    head = temp;
}

// * insert at tail
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    temp->pre = tail;
    tail = temp;
}

// ? insert at any position
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // * insert at head
    if (position == 1)
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
    temp->next->pre = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->pre = temp;
}

// * delete node at any position
void deleteNode(int position, Node *&head, Node* &tail)
{
    // * first node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->pre = NULL;
        head = temp->next ; //? ab  head ko temp ka next ho jayega
        // * memory free kar do
        temp->next = NULL; //* delete karne se pahle temp ko null point kea do nahi toh segmentaion falut
        delete temp;
    }
    else
    {
        // * delete middle ya last node
        Node *pre = NULL;
        Node *curr = head;
        int cnt = 1;
        while (cnt < position - 1)
        {
            pre = curr;
            curr = curr->next;
            cnt++;
        }

        curr -> pre = NULL;
        pre -> next = curr -> next;

        curr->next = NULL; //? delete karne se pahle null point kra do

        // * line 133 se 136 tail ko update kar raha nahi toh delete hone ke baad garbage value dega
        if (pre->next == NULL)
        {
            tail = pre; //* Update tail if last node is deleted
        }
        delete curr;
    }
}

int main()
{
    Node *node1 = new Node(10); //* agar koiee node n ho toh yani head and tail both are NULL->>specail case file
    Node *head = node1;
    Node *tail = node1;
    print(head);
    // cout << "lenght of LL-->>" << getLenght(head) << endl;

    // * insert at head
    insertAtHead(head, 9);
    print(head);
    insertAtHead(head, 8);
    print(head);
    insertAtHead(head, 7);
    print(head);

    // * insert at Tail
    insertAtTail(tail, 11);
    print(head);
    insertAtTail(tail, 12);
    print(head);
    insertAtTail(tail, 13);
    print(head);

    // * insert at any position
    insertAtPosition(head, tail, 1, 6);
    print(head);
    insertAtPosition(head, tail, 9, 101);
    print(head);
    insertAtPosition(head, tail, 6, 100);
    print(head);

    // * delete any node 
    deleteNode(11, head, tail);
    print(head);
    cout<<"head is->>"<<head->data<<endl;
    cout<<"tail is->>"<<tail->data<<endl;
    return 0;
}