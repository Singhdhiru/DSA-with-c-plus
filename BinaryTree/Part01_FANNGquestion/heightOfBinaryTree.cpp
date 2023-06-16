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

int heightOfBinaryTree(Node* root){
    // base case
    if(root == NULL){
        return 0;
    }

    int left = heightOfBinaryTree(root->left);
    int right = heightOfBinaryTree(root->right);
    int ans = max(left, right) + 1;
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
int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right  = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // print the values
    printTree(root);
    cout<<endl;

    cout<<"height of Binary Tree->>"<<heightOfBinaryTree(root)<<endl;
    return 0;
}