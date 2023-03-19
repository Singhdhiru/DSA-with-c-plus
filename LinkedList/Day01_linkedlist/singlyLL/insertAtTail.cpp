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

// * insert at tail in LL
void insertAtTail(Node* &tail, int d){

    Node* temp = new Node(d);//* create temp node 
    tail->next = temp;
    tail = temp; 
}

// * print the linked list
// void print(Node* &head){
//     Node* temp = head; 
//     while(temp != NULL){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
//     cout<<endl;
// }

void print(Node* &tail){
    Node* temp = tail; 
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    // cout<<endl;
}
int main()
{
    // * create object dynamically
    Node *node1 = new Node(10); 
    cout<<"intially present element in linkedlist-->>>";
    cout<<node1->data<<endl;

    cout<<"add element at tail then linkedlist is->>";
    // * create the new tail
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, 13);
    print(tail);
    insertAtTail(tail, 14);
    print(tail);
    insertAtTail(tail, 15);
    print(tail);
    return 0;
}