#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // purana level complete traversal ho chuka hi
            cout << endl;
            if (!q.empty())
            {
                // queue still has some childernels
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder(struct Node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node *inorderToBst(int s, int e, vector<int> &in)
{
    // base case
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    Node *root = new Node(in[mid]);
    root->left = inorderToBst(s, mid - 1, in);
    root->right = inorderToBst(mid + 1, e, in);
    return root;
}
// Your are required to complete this function
// function should return root of the modified BST
Node *buildBalancedTree(Node *root)
{
    // save inorder in vector
    vector<int> inorderVal;
    inorder(root, inorderVal);

    return inorderToBst(0, inorderVal.size() - 1, inorderVal);
}
Node *insertIntoBst(Node *root, int data)
{
    // base case
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        // left part mai insert karna h
        root->right = insertIntoBst(root->right, data);
    }
    else
    {
        // left part mia insert karna hi
        root->left = insertIntoBst(root->left, data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}
int main()
{
    Node *root = NULL;
    cout << "Enter the data to create BST (-1 to stop): ";
    takeInput(root);
    cout << endl;

    cout << "Level order traversal: " << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Building balanced BST..." << endl;
    root = buildBalancedTree(root);

    cout << "Level order traversal of balanced BST: " << endl;
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
