#include <iostream>
#include <map>
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
Node *floydCycle(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (fast == slow)
        {
            return slow;
        }
    }
    return NULL;
}

Node *startingNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *intersection = floydCycle(head);
    if (intersection == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
Node* removeLoop(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* startLoop = startingNode(head);
    if(startLoop == NULL){
        return NULL;
    }
    // * create pointer point to the starting node of cyclic LL
    Node* temp = startLoop;
    while(temp->next != startLoop){
        temp = temp->next;
    }
    temp -> next = NULL;
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
    cout << endl;
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
    print(head);

    // ?insert at tail
    insertAtTail(tail, 14);
    print(tail);
    insertAtTail(tail, 15);
    print(tail);
    // * insert at given position
    insertAtPosition(head, tail, 1, 33);
    print(head);

    // ? make the loop
    tail->next = head->next; //* write a code to check loop or not

    // * second method
    if (floydCycle(head) != NULL)
    { //* agar loop hoga toh slow return karega jo NULL nahi hoga yani else block
        cout << "loop is not present" << endl;
    }
    else
    {
        cout << "loop is present" << endl;
    }
    // * find starting node
    Node *loopStart = startingNode(head);
    cout << "starting node of cyclic LL is ->>" << loopStart->data << endl;
    // * remove LOOP
    removeLoop(head);
    print(head);
    return 0;
}