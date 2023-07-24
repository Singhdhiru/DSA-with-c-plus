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

// Function to perform postorder traversal and rebuild the tree as a max heap
void postorder(Node* root, vector<int>& in, int& index) {
    if (root == nullptr)
        return;

    postorder(root->left, in, index);
    postorder(root->right, in, index);

    root->data = in[index++];
}

// Function to convert the binary tree to a max heap
void convertToMaxHeapUtil(Node* root) {
    vector<int> in;
    inorder(root, in);
    int index = 0;
    postorder(root, in, index);
}

// Function to print the tree using inorder traversal (to check the max heap conversion)
void printInorder(Node* root) {
    if (root == nullptr)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(4);
    root->left = new Node(6);
    root->right = new Node(2);
    root->left->left = new Node(8);
    root->left->right = new Node(5);
    root->right->left = new Node(3);
    root->right->right = new Node(1);

    cout << "Original tree (inorder): ";
    printInorder(root);
    cout << endl;

    convertToMaxHeapUtil(root);

    cout << "Max heap converted tree (inorder): ";
    printInorder(root);
    cout << endl;

    return 0;
}
