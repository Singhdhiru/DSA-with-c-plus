#include<iostream>
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

void inorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

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
    root->left = new Node(3);
    root->right  = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(11);
    root->right->left = new Node(17);
    // root->right->right = new Node(7);

    // print the values
    printTree(root);
    cout<<endl;
    cout << "inorder traversal is:  ";
    inorder(root); 

    // cout << endl << "preorder traversal is:  ";
    // preorder(root); 

    // cout << endl << "postorder traversal is:  ";
    // postorder(root); 
    return 0;
}