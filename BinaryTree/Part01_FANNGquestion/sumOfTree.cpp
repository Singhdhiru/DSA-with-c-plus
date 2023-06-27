#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

pair<bool, int> solve(Node* root){
        // base case
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        // handle leaf Node
        if(root->left == NULL && root->right == NULL){
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool ,int> leftAns = solve(root->left);
        pair<bool, int> rightAns = solve(root->right);
        
        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;
        
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        
        bool condn = root->data == leftSum + rightSum;
        
        pair<bool, int> ans;
        if(isLeftSumTree && isRightSumTree && condn){
            ans.first = true;
            ans.second = root->data + leftSum + rightSum;
        }
        else{
            ans.first = false;
        }
        return ans;
    }


void printTree(Node* node) {
    if (node == NULL)
        return;

    // Print the value of the current node
    cout << node->data << " ";

    // Recursively print the left and right subtrees
    printTree(node->left);
    printTree(node->right);
}
int main() {
    struct Node* root = new Node(1);
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

    // Check if the binary tree is a sum tree
    pair<bool, int> result = solve(root);
    if (result.first)
        cout << "The binary tree is a sum tree." << endl;
    else
        cout << "The binary tree is not a sum tree." << endl;

    return 0;
}