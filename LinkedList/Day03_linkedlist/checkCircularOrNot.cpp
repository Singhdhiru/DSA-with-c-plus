#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // * constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

// * insert data
void insertNode(Node *&tail, int element, int d)
{

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        // assuming that the element is present in the list

        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found -> curr is representing element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

// * check it is circular or not
bool checkCircular(Node* &head){
    // * empty list
    if(head == NULL){
        return true;
    }
    // * 1 node present
    if(head->next == NULL){
        return false;
    }
    // * >1 node
    Node* temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    if(temp == NULL){
        return false;
    }
    if(temp == head){
        return true;
    }
}
// * print circular linkedlist
void print(Node *&tail)
{
    Node *temp = tail;

    //? empty list
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 3, 4);
    print(tail);
    insertNode(tail, 4, 5);
    print(tail);
    insertNode(tail, 5, 6);
    print(tail);
    if(checkCircular){
        cout<<"LL is circular"<<endl;
    }
    else{
        cout<<"LL is not circular"<<endl;
    }
    return 0;
}