// ? method 02->>
// #include <iostream>
// #include <bits/stdc++.h>
// #include <stack>
// using namespace std;

// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;

//     Node(int val)
//     {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// Node* solve(Node* root, int &k, int node) {
//     //base case
//     if(root == NULL)
//         return NULL;

//     if(root->data == node)
//     {
//         return root;
//     }

//     Node* leftAns = solve(root->left, k, node);
//     Node* rightAns = solve(root->right, k, node);

//     //wapas
//     if(leftAns != NULL && rightAns == NULL)
//     {
//         k--;
//         if(k<=0)
//         {
//             //answer lock
//             k = INT_MAX;
//             return root;
//         }
//         return leftAns;
//     }

//     if(leftAns == NULL && rightAns != NULL) {
//         k--;
//         if(k<=0)
//         {
//             //answer lock
//             k = INT_MAX;
//             return root;
//         }
//         return rightAns;
//     }
//     return NULL;

// }
// int kthAncestor(Node *root, int k, int node)
// {
//     Node* ans = solve(root, k, node);
//     if(ans == NULL || ans->data == node)
//         return -1;
//     else
//         return ans->data;
// }
// void printTree(Node *node)
// {
//     if (node == NULL)
//         return;

//     // Print the value of the current node
//     cout << node->data << " ";

//     // Recursively print the left and right subtrees
//     printTree(node->left);
//     printTree(node->right);
// }
// int main()
// {
//     struct Node *root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->left = new Node(6);
//     root->right->right = new Node(7);

//     // Print the values of the binary tree
//     cout << "Binary Tree: ";
//     printTree(root);
//     cout << endl;

//     int k = 2;
//     int givenNode = 7;
//     cout<<"kt ancestor of a node -->> "<<kthAncestor(root, k, givenNode);
//     return 0;
// }
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

int ans = -1;
void solve(Node *root, int k, int node, vector<int> &v)
{
    if (root == NULL)
        return;

    if (root->data == node)
    {
        if (v.size() >= k)
            ans = v[v.size() - k];
        else
            ans = -1;
        return;
    }
    v.push_back(root->data);
    solve(root->left, k, node, v);
    solve(root->right, k, node, v);
    v.pop_back();
}
// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{
    if (root == NULL)
        return -1;

    vector<int> v;
    solve(root, k, node, v);
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

    int k = 2;
    int givenNode = 7;
    cout << "kt ancestor of a node -->> " << kthAncestor(root, k, givenNode);
    return 0;
}
