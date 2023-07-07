#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

int findposition(int in[], int inorderstart, int inorderend, int element, int n) // O(n)
{
    for (int i = inorderstart; i <= inorderend; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node *solve(int in[], int post[], int &index, int inorderstart, int inorderend, int n) // O(n)
{
    if ((index < 0) || (inorderstart > inorderend))
    {
        return NULL;
    }

    int element = post[index--];
    Node *root = new Node(element);
    int position = findposition(in, inorderstart, inorderend, element, n); // O(n).

    root->right = solve(in, post, index, position + 1, inorderend, n);
    root->left = solve(in, post, index, inorderstart, position - 1, n);
    return root;
}
// Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n)
{
    int postorderindex = n - 1;
    Node *ans = solve(in, post, postorderindex, 0, n - 1, n);
    return ans;
}
// Function to display the constructed binary tree (pretorder traversal)
void displayInorder(Node *node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    displayInorder(node->left);
    displayInorder(node->right);
}
int main()
{
    int n = 8;
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};

    Node *finalAnswer = buildTree(in, post, n);

    // Display the constructed binary tree (inorder traversal)
    displayInorder(finalAnswer);

    return 0;
}