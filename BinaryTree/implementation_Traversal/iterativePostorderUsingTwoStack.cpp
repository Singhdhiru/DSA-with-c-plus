#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void iterativePostorder(Node *root)
{
    if (root == NULL)
        return;
    
    // create two stack
    stack<Node*>s1;
    stack<Node*>s2;
    s1.push(root);
    while(!s1.empty()){
        // pop s1 and push it in s2
        struct Node* temp = s1.top();
        s1.pop();
        s2.push(temp);

        // push left and right children
        if(temp->left ){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
    }
    // print all element of second stack
    while(!s2.empty()){
        struct Node* temp = s2.top();
        s2.pop();
        cout<<temp->data<<" ";
    }
}

void printTree(Node *node)
{
    if (node == NULL)
        return;

    // Print the value of the current node
    cout << node->data << " ";

    // Recursively print the left and right subtrees
    printTree(node->left);
    printTree(node->right);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // print the values
    printTree(root);
    cout << endl;

    cout<<"print the iterative traversal of binary tree->>";
    iterativePostorder(root);
    return 0;
}