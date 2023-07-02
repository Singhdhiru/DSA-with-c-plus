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

void solve(Node *root, int k, unordered_map<int, int> &pathSumCount, int currSum, int &count)
{
    if (root == nullptr)
    {
        return;
    }

    currSum += root->data;

    if (currSum == k)
    {
        count++;
    }

    if (pathSumCount.find(currSum - k) != pathSumCount.end())
    {
        count += pathSumCount[currSum - k];
    }

    pathSumCount[currSum]++;

    solve(root->left, k, pathSumCount, currSum, count);
    solve(root->right, k, pathSumCount, currSum, count);

    pathSumCount[currSum]--;
}

int sumK(Node *root, int k)
{
    unordered_map<int, int> pathSumCount;
    int count = 0;
    solve(root, k, pathSumCount, 0, count);
    return count;
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

    int k = 7;
    cout<<"k sum path-->> "<<sumK(root, k);
    return 0;
}
