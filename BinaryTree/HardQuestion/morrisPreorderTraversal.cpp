#include <iostream>
#include <bits/stdc++.h>
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
vector<int> getPreorder(Node *root)
{
    vector<int> Prorder;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            Prorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if(prev -> right == NULL){
                prev->right = curr;
                Prorder.push_back(curr->data);
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return Prorder;
}

// this is print preorder function
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
    cout << endl;

    cout<<"morris preorder traversal->> ";
    vector<int> finalAns = getPreorder(root);
    for(auto i: finalAns){
        cout<<i<<" ";
    }

    return 0;
}