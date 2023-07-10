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
Node *LCA(Node *root, int n1, int n2)
{
    // method ->> 01 => iterative method
    // while(root != NULL){
    //     if(root->data>n1 && root->data>n2){
    //         root = root->left;
    //     }
    //     else if(root->data<n1 && root->data<n2){
    //         root = root->right;
    //     }
    //     else{
    //         return root;
    //     }
    // }

    // method->> 02 => recursive solution
    // base case
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > n1 && root->data > n2)
    {
        root = LCA(root->left, n1, n2);
    }
    if (root->data < n1 && root->data < n2)
    {
        root = LCA(root->right, n1, n2);
    }
    else
    {
        return root;
    }
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
        // right part mai insert karna h
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

    // Find the Lowest Common Ancestor (LCA)
    int n1, n2;
    cout << "Enter two nodes to find their Lowest Common Ancestor: ";
    cin >> n1 >> n2;
    Node *lcaNode = LCA(root, n1, n2);
    if (lcaNode != NULL)
    {
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lcaNode->data << endl;
    }
    else
    {
        cout << "Lowest Common Ancestor does not exist." << endl;
    }

    return 0;
}