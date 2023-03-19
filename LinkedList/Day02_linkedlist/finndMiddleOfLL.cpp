// * find the middle of linkelist 
// ? two method are present
// ? 1-> using find the lenght of LL 
// * 2-> using slow and fast pointer

// ? method-->>>1
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


int getLenght(Node* head){
    int lenght = 0;
    while(head != NULL){
        lenght++;
        head= head->next;
    }
    return lenght;
}

// * find the middle of Linkdlist
Node* middleLL(Node* head, int lenght){
    int ans = lenght/2;
    //* hack--->> return node not lenght;
    Node* temp = head;
    int cnt = 0;
    while(cnt<ans){
        temp = temp->next;
        cnt++;
    }
    return temp;
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
    insertAtPosition(head, tail ,4, 13);
    print(head);
    
    int len = getLenght(head);
    Node* middlenode = middleLL(head, len);
    cout<<"middle node of linkedlist is->>"<<middlenode->data<<endl;


    return 0;
}