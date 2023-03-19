#include <iostream>
using namespace std;

// * create the node class
class Node
{
public:
    int data;
    // * cretate pointer to store the addres on next data
    Node *next;

    // * constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// * insert at head in LL
void insertAtHead(Node* &head, int d){

    Node* temp = new Node(d);//* create temp node 
    temp->next = head; //* temp node ka next head yani node1 ko point karege
    head = temp; //* then temp ko hi head node bna denge
}

// * insert at tail in LL
void insertAtTail(Node* &tail, int d){

    Node* temp = new Node(d);//* create temp node 
    tail->next = temp;
    tail = temp; 
}


// * print the linked list
void print(Node* &head){
    Node* temp = head; //* create temp node jo head ko point karege
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    // * create object dynamically
    Node *node1 = new Node(10); 
    cout<<"intially present element in linkedlist-->>>";
    cout<<node1->data<<endl;

    cout<<"add element at head then linkedlist is->>";
    // * create the new head
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head, 13);
    print(head);
    insertAtTail(tail, 15);
    insertAtTail(tail, 16);
    print(tail);

    return 0;
}