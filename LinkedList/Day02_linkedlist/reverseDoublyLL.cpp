#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* pre;
    // * constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
        this->pre = NULL;

    }
};
void insertAtHead(Node* &head , int data){
    Node *temp = new Node(data);
    temp->next = head;
    head->pre = temp;
    head = temp;
}
void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    temp->pre = tail;
    tail = temp;
}
void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    // * insert at head
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    int cnt = 1 ;
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
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->pre = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->pre = temp;
    
}
// * iterative solution
void reverseDoublyLL(Node* &head){
    Node* temp = NULL;
    Node* current = head;
    //? swap next and pre pointers for all nodes of the list
    while (current != NULL) {
        temp = current->pre;
        current->pre = current->next;
        current->next = temp;
        current = current->pre;
    }
    //? check if list is not empty
    if (temp != NULL) {
        head = temp->pre;
    }
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtHead(head, 9);
    print(head);
    insertAtTail(tail, 11);
    print(head);
    insertAtPosition(head, tail, 2, 23);
    print(head);
    reverseDoublyLL(head);
    print(head);
    return 0;
}