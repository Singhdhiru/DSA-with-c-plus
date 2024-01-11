#include<iostream>
#include<stack>
using namespace std;
// leet code->404
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

int solve(Node* root, int &sum) {
    if (root == NULL) {
        return 0;
    }
    if (root->left && root->left->left == NULL &&
        root->left->right == NULL) {
        sum += root->left->data;
    }
    solve(root->left, sum);
    solve(root->right, sum);
    return sum;
}

int sumOfLeftLeaves(Node* root) {
    int sum = 0;
    int ans = solve(root, sum);
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
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    // Print the values
    printTree(root);
    cout << endl;

    int sum_of_left_leaves = sumOfLeftLeaves(root);
    cout<<"sum of left leaves->"<<sum_of_left_leaves<<endl;
    return 0;
}