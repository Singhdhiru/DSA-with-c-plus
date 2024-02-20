#include<bits/stdc++.h>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=Q05ZTiqgBtw
    Company Tags                : 24*7 Innovation Labs, Amazon, Drishti-Soft, Flipkart, Goldman Sachs, Microsoft, Paytm, Payu, Snapdeal, Visa
    Leetcode Link               : https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
 */   
class Node{
    public:
    int data;
	Node * next;
	Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
};
//T.C : O(N*N*M) See my detailed video above to understand this.
//S.C : Auziliary Space = O(1) and O(N*M) – because of the recursion.

// * LAst mai flatten linkL ko print kar dunga
void PrintFlattenLl(Node* root){
    while(root != NULL){
        cout<<root->data<<" ";
        root = root->bottom;
    }
}
// Function to merge two linked lists in sorted order
Node* mergeTwoLists(Node* head1, Node* head2) {
    // If one of the linked lists is empty, return the other
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    Node* result;
    // Compare the nodes and merge them in sorted order
    if (head1->data < head2->data) {
        result = head1;
        // Recursively merge the rest of the nodes
        result->bottom = mergeTwoLists(head1->bottom, head2); //Trust
    } else {
        result = head2;
        // Recursively merge the rest of the nodes
        result->bottom = mergeTwoLists(head1, head2->bottom); //Trust
    }

    return result;
}

Node *flatten(Node *head) {
    if(!head)
        return head;

    Node* temp = flatten(head->next);
    
    return mergeTwoLists(head, temp);
} 
int main() {
    Node* head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->bottom = new Node(20);
    head1->next->next = new Node(19);
    head1->next->next->bottom = new Node(22);
    head1->next->next->next = new Node(28);

    Node* head2 = new Node(7);
    head2->bottom = new Node(8);
    head2->bottom->bottom = new Node(30);
    head2->next = new Node(9);
    head2->next->bottom = new Node(15);

    Node* head3 = new Node(12);
    head3->next = new Node(14);
    head3->next->bottom = new Node(21);

    // Connect the lists horizontally
    head1->next->next->next->next = head2;
    head1->next->next->next->next->next = head3;

    // ? Flatten linkL
    Node* flattenLL = flatten(head1);

    // ? print all node after flatten
    PrintFlattenLl(flattenLL);


    return 0;
}