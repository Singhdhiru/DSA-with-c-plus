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

  //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        map<int, int> topNode;
        queue<pair<Node*, int>>q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            pair<Node*, int>temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            // if one value is present for hd , then do nothing
            if(topNode.find(hd) == topNode.end()){
                topNode[hd] = frontNode->data;
            }
            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd-1));
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }
        
        for(auto i: topNode){
            ans.push_back(i.second);
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

    cout<<"top view-->> ";
    vector<int> finalAns = topView(root);
    for(auto i: finalAns){
        cout<<i<<" ";
    }

    return 0;
}