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
int main()
{
    // * create object dynamically
    Node *node1 = new Node(10); //* create the first object of node class--->>>>node of linked list
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    return 0;
}