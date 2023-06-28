#include <iostream>
#include <bits/stdc++.h>
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

void traverseLeft(Node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void traverseLeaf(Node *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    // wapas aagye
    ans.push_back(root->data);
}
vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL)
            return ans;
            
        ans.push_back(root->data);
        
        //left part print/store
        traverseLeft(root->left, ans);
        
        //traverse Leaf Nodes
        
        //left subtree
        traverseLeaf(root->left, ans);
        //right subtree
        traverseLeaf(root->right, ans);
        
        //traverse right part
        traverseRight(root->right, ans);
        
        return ans;
        
        
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

    // Print the values of the binary tree
    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    cout<<"boundray Traversal->> ";

    vector<int> finalAns = boundary(root);
    for(auto i: finalAns){
        cout<<i<<" ";
    }

    return 0;
}