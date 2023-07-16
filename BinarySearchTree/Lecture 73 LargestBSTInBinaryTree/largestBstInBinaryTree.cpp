#include <iostream>
#include <limits.h>
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

class info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(Node *root, int &ans)
{
    // base case
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    // answer update
    if (currNode.isBST)
    {
        ans = max(ans, currNode.size);
    }

    return currNode;
}
/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
int largestBst(Node *root)
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
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
    cout<<endl;
    cout<<"largest BST present in binary tree: "<<largestBst(root);
    return 0;
}