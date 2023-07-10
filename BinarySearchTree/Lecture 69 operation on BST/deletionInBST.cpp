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
Node *minValue(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *maxValue(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
Node* deleteFromBST(Node* root, int value){
    // base case
    if(root == NULL){
        return root;
    }
    if(root->data == value){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        // left child
        if(root->left != NULL && root->right ==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if(root->left == NULL && root->right !=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // two child
        if(root->left != NULL && root->right != NULL){
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }

    }
    else if(root->data > value){
        // left part mai jaoo
        root->left = deleteFromBST(root->left, value);
        return root;
    }
    else{
        // right part mai jaoo
        root->right = deleteFromBST(root->right, value);
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

    cout<<"Max value in BST:"<<maxValue(root)->data<<endl;
    cout<<"min value in the BST:"<<minValue(root)->data<<endl;

    deleteFromBST(root, 12);
    cout << "Level order traversal: " << endl;
    levelOrderTraversal(root);
    cout << endl;
    return 0;
}