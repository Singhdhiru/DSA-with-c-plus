#include <iostream>
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

void inorder(Node*root, int &count)
{
    // base case
    if (root == NULL)
    {
        return ;
    }

    inorder(root->left, count);

    // leaf node
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }

    inorder(root->right, count);
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
    cout<<endl;
    // number of leaf node
    int cnt = 0;
    inorder(root, cnt);
    // print the value of cnt
    cout << "Number of leaf nodes: " << cnt << endl;
    return 0;
}