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

    //*destructor
    ~Node() {
        int value = this -> data; //? delete karne se pahle store kar ke print karna hi
        //*memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
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

// * delete node
void deleteNode(int position, Node* &head, Node* &tail){
    // * first node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        // * memory frezz kar do 
        temp->next = NULL; //* delete karne se pahle temp ko null point kea do nahi toh segmentaion falut
        delete temp;
    }
    else{
        // * delete middle ya last node
        Node* pre = NULL;
        Node* curr = head;
        int cnt = 1 ;
        while(cnt<position-1){
            pre = curr;
            curr = curr->next;
            cnt++;
        }
        pre->next = curr->next;
        curr->next = NULL; //? delete karne se pahle null point kra do
        if (pre->next == NULL) {
            tail = pre; //* Update tail if last node is deleted
        }
        delete curr;
    }
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
    print(head);

    // ?insert at tail
    insertAtTail(tail, 14);
    print(tail);
    insertAtTail(tail, 15);
    print(tail);
    cout<<endl;
    // * insert at given position
    insertAtPosition(head, tail, 1, 33);
    print(head);
    cout<<endl;

    cout<<"head data is->>"<<head->data<<endl;
    cout<<"tail data is ->>"<<tail->data<<endl;
    // * delete element
    deleteNode(7, head, tail);
    cout<<endl;
    print(head); 
    cout<<"head data is->>"<<head->data<<endl;
    cout<<"tail data is ->>"<<tail->data<<endl; //* this line give grabage how to fix this ->> line number 106 see
    
    return 0;
}