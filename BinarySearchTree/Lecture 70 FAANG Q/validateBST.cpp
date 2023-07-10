#include <iostream>
#include<climits>
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
bool solve(Node *root, int &mini, int &maxi)
{
    if (root == NULL)
        return true;
    if (root->data <= maxi && root->data >= mini)
    {
        bool left = solve(root->left, mini, root->data);
        bool right = solve(root->right, root->data, maxi);
        return left && right;
    }
    else
        return false;
}
bool validateBST(Node *root)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    return solve(root, mini, maxi);
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
    root->right = new Node(15);
    root->left->left = new Node(7);
    root->left->right = new Node(9);
    root->right->left = new Node(14);
    root->right->right = new Node(17);

    // print the values
    printTree(root);
    cout<<endl<<"check the Binary Tree is BST or Not :"<<validateBST(root);
    return 0;
}