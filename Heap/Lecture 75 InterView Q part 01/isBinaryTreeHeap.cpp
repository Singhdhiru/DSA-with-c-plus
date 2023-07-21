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

int Nodecount(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int ans = 1 + Nodecount(root->left) + Nodecount(root->right);
        return ans;
    }
}
int CBT(Node *root, int index, int totalcount)
{
    if (root == NULL)
    {
        return true;
    }
    if (index >= totalcount)
    {
        return false;
    }
    else
    {
        int left = CBT(root->left, 2 * index + 1, totalcount);
        int right = CBT(root->right, 2 * index + 2, totalcount);
        return (left && right);
    }
}
int maxheap(Node *root)
{
    // both child are NULL
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    // only left child are present
    if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    // both child are present
    else
    {
        bool left = maxheap(root->left);
        bool right = maxheap(root->right);
        return (left && right &&(root->data > root->left->data &&root->data > root->right->data));
    }
}
bool isHeap(struct Node *tree)
{
    // tree is given as the root
    int index = 0;
    int totalcount = Nodecount(tree);
    if (CBT(tree, index, totalcount) && maxheap(tree))
    {
        return true;
    }
    else
    {
        return false;
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
    struct Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(9);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    // print the values
    printTree(root);
    cout<<endl;

    cout<<"Is binary tree is max heap or not: "<<isHeap(root)<<endl;

    return 0;
}