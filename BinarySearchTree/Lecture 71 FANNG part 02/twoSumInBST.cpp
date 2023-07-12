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
// root : the root Node of the given BST
// target : the target sum
int isPairPresent(struct Node *root, int target)
{
    vector<int> inorderVal;
    inorder(root, inorderVal);

    int i = 0;
    int j = inorderVal.size() - 1;
    while (i < j)
    {
        int sum = inorderVal[i] + inorderVal[j];
        if (sum == target)
        {
            return 1;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return 0;
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

    if(isPairPresent(root,300)){
        cout<<"target value is exist in BST  "<<endl;
    }
    else{
        cout<<"Not present: ";
    }
    return 0;
}