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
bool searchInBST(Node *root, int x)
{
    // method ->>. 01
    // iterative solution
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return true;
        }
        if (temp->data > x)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;

    // method ->>> 02
    // recursive solution ->>>>> give tle
    // base case
    // if(root == NULL){
    //     return false;
    // }
    // if(root->data == x ){

    //     return true;
    // }
    // if(root->data > x){
    //     left mai jaoo
    //     return searchInBST(root->left, x);
    // }
    // else{
    //      right mai jaoo
    //     return searchInBST(root->right, x);
    // }
}
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

    int x = 10;
    cout<<"search the elements in BST->> "<<searchInBST(root, x);
    return 0;
}