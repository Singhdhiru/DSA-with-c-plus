#include <iostream>
#include<unordered_map>
using namespace std; // Use the standard namespace

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *random; // Pointer to a random node

    Node(int val) : data(val), left(nullptr), right(nullptr), random(nullptr) {}
};

//* Approach 1 : Using Recursion + map
//* Time Complexity : 0(n);
//* Space Complexity : 0(n);
Node *copyLeftRightNode(Node *treeNode, unordered_map<Node *, Node *> &mymap)
{
    if (treeNode == NULL)
        return NULL;
    Node *cloneNode = new Node(treeNode->data);
    mymap[treeNode] = cloneNode;
    cloneNode->left = copyLeftRightNode(treeNode->left, mymap);
    cloneNode->right = copyLeftRightNode(treeNode->right, mymap);
    return cloneNode;
}

// This function copies random node by using the hashmap built by
// copyLeftRightNode()
void copyRandom(Node *treeNode, unordered_map<Node *, Node *> &mymap)
{
    if (treeNode == NULL)
        return;
    mymap[treeNode]->random = mymap[treeNode->random];
    copyRandom(treeNode->left, mymap);
    copyRandom(treeNode->right, mymap);
}
Node* cloneTree(Node* tree)
{
    if (tree == NULL)
        return NULL;
    unordered_map<Node *, Node *> mymap;
    Node* newTree = copyLeftRightNode(tree, mymap);
    copyRandom(tree, mymap);
    return newTree;
}

//* Approach 2 : Using Recursion
//* Time Complexity : 0(n);
//* Space Complexity : 0(1);
/*Node *cloneTree(Node *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    Node *newNode = new Node(tree->data);
    newNode->random = tree->random;          // Copy the random pointer
    newNode->left = cloneTree(tree->left);   // Recursively clone left subtree
    newNode->right = cloneTree(tree->right); // Recursively clone right subtree

    return newNode;
}*/

// Helper function to print the tree (for demonstration purposes)
void printTree(Node *node)
{
    if (node == NULL)
        return;

    cout << "Node: " << node->data;

    if (node->random)
    {
        cout << ", Random: " << node->random->data;
    }
    else
    {
        cout << ", Random: NULL";
    }

    cout << endl;

    printTree(node->left);
    printTree(node->right);
}

int main()
{
    // Create a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    // Setting up random pointers for demonstration
    root->random = root->right;       // Random pointer of root points to node 3
    root->left->random = root;        // Random pointer of node 2 points to root
    root->right->random = root->left; // Random pointer of node 3 points to node 2

    cout << "Original Tree:" << endl;
    printTree(root);

    //* Approach : 2
    // Node *clonedTree = cloneTree(root);

    // * Approach : 1
    Node* clonedTree = cloneTree(root);


    cout << "\nCloned Tree:" << endl;
    printTree(clonedTree);

    // Clean up memory (not shown for simplicity)

    return 0;
}