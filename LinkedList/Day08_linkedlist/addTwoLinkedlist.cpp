#include<bits/stdc++.h>
using namespace std;

// Node structure
struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

// Function to add two linked lists
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* curr = dummy;
    int carry=0;
    while(l1!=NULL || l2!=NULL){
        int sum=0;
        if(l1!=NULL){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node* node=new Node(sum%10);
        curr->next=node;
        curr=curr->next;
    }
    if(carry>0){
        Node* node=new Node(carry);
        curr->next=node;
        curr=curr->next;
    }
    return dummy->next;
}

// Function to print the linked list
void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

// Driver code
int main(){
    // Creating first linked list
    Node* l1=new Node(1);
    l1->next=new Node(9);
    l1->next->next=new Node(0);
    Node* head1 = l1;
    printList(head1);
    // Creating second linked list
    Node* l2=new Node(2);
    l2->next=new Node(5);
    Node* head2 = l2;
    printList(head2);
    // Adding two linked lists
    Node* sum=addTwoNumbers(l1,l2);

    // Printing the resultant linked list
    printList(sum);

    return 0;
}
