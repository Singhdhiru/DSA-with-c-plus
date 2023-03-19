// * find the middle of linkelist 
// *method  2-> using slow and fast pointer
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

// * find the middle of Linkdlist
Node* getMiddle(Node* head){
    
    // ? 1 node ho ya ak bhi nahi
    if(head == NULL || head->next == NULL){
        return head;
    }
    // * jab 2 node ho toh
    if(head->next->next == NULL){
        return head->next;
    }

    // * 2 se jayada ho toh ->> using slow and fast pointer
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL){
        fast = fast->next ;
        // * null na ho toh ak aur bada do
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
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
    
    Node* middlenode = getMiddle(head);
    cout<<"middle node of linkedlist is->>"<<middlenode->data<<endl;


    return 0;
}