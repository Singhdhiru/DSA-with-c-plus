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
Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    Node *ans = new Node(-1);
    Node *temp = ans;

    // ?merge 2 sorted Linked List
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}
Node *mergeSort(Node* &head)
{
    //?base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    //? break linked list into 2 halvs, after finding mid
    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    //?recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    //?merge both left and right halves
    Node *result = merge(left, right);

    return result;
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
    cout << "first node->>" << node1->data << endl;

    Node *head = node1;
    Node *tail = node1;

    // * insert at head
    insertAtHead(head, 12);
    insertAtHead(head, 11);

    // ?insert at tail
    insertAtTail(tail, 14);
    insertAtTail(tail, 15);
    insertAtPosition(head, tail, 1, 33);
    print(head);
    cout<<endl;
    // ? sort linked list using merge sort
    Node* final = mergeSort(head);
    print(final);

    return 0;
}