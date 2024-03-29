#include <iostream>
#include <vector>
using namespace std;

// Structure of the binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform inorder traversal and store values in 'in' vector
void inorder(Node* root, vector<int>& in) {
    if (root == nullptr)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

// Function to perform postorder traversal and rebuild the tree as a min heap
void postorder(Node* root, vector<int>& in, int& index) {
    if (root == nullptr)
        return;

    postorder(root->right, in, index);
    postorder(root->left, in, index);

    root->data = in[index++];
}

// Function to convert the binary search tree to a min heap
void convertToMinHeapUtil(Node* root) {
    vector<int> in;
    inorder(root, in);
    int index = 0;
    postorder(root, in, index);
}

// Function to print the tree using inorder traversal (to check the min heap conversion)
void printInorder(Node* root) {
    if (root == nullptr)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    // Create a sample binary search tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    cout << "Original BST (inorder): ";
    printInorder(root);
    cout << endl;

    convertToMinHeapUtil(root);

    cout << "Min heap converted tree (inorder): ";
    printInorder(root);
    cout << endl;

    return 0;
}
