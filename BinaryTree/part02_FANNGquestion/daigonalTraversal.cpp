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

vector<int> diagonalTraversal(Node* root){
    vector<int> ans;
    if (root == nullptr) {
        return ans;
    }

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        while (temp) {
            if (temp->left) {
                q.push(temp->left);
            }
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
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

    cout << "diagonal Traversal-->> ";
    vector<int> finalAns = diagonalTraversal(root);
    for (auto i : finalAns)
    {
        cout << i << " ";
    }
    return 0;
}