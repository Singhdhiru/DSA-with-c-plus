#include <iostream>
#include<bits/stdc++.h>
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

// Function to store the zig zag order traversal of tree in a list.
vector<int> zigZagTraversal(Node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;

    queue<Node *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {

        int size = q.size();
        vector<int> ans(size);

        // Level Process
        for (int i = 0; i < size; i++)
        {

            Node *frontNode = q.front();
            q.pop();

            // normal insert or reverse insert
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);

            if (frontNode->right)
                q.push(frontNode->right);
        }

        // direction change karni h
        leftToRight = !leftToRight;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
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

    cout<<"zig zag traversal->> ";
    vector<int>finalAns = zigZagTraversal(root);
    for(int i=0; i<finalAns.size(); i++){
        cout<<finalAns[i]<<" ";
    }

    return 0;
}