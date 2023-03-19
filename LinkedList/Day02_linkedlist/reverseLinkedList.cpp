#include<iostream>
using namespace std;
class Node{
    public:
    int data ;
    Node* next;
    // * constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(Node* &head, Node* &tail, int position , int data){
    if(head == NULL || position == 1){
        insertAtHead(head, data);
        return;
    }

    int cnt = 1;
    Node* temp = head;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertAtTail(tail, data);
        return ;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// * reverse linkedlist->> iterative way
Node* reverseLLIterative(Node* &head){
    // ? jab 1 hi node ho ya koiee node n ho
    if(head == NULL || head->next == NULL){
        return head;
    }

    // * use the pointer 
    Node* pre = NULL;
    Node* curr= head;
    Node* forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forward;
    }
    return pre;

}

// * reverse linkedlist recursive way
Node* reverseLLRecur(Node* &head){
    // ? base case
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = reverseLLRecur(head->next); //* pehla node ham solve akrenge uske baad recursion dekh lega
    //* pahle node handle kar liya
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertAtHead(head,9);
    print(head);
    insertAtTail(tail, 11);
    print(head);
    insertAtPosition(head, tail, 1, 8);
    print(head);
    insertAtPosition(head, tail ,3, 12);
    print(head);
    // cout<<endl;
    insertAtPosition(head, tail, 3, 15);
    print(head);
    // ? reverse linkedlist iterative way
    // Node* newNode = reverseLLIterative(head);
    // print(newNode);
    //? reverse by recursion
    Node* newNode2 = reverseLLIterative(head);
    print(newNode2);

    return 0;
}