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

int findposition(int in[], int inorderstart, int inorderend, int element, int n)
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

Node *solve(int in[], int pre[], int &index, int inorderstart, int inorderend, int n)
{
    if ((index >= n) || (inorderstart > inorderend))
    {
        return NULL;
    }

    int element = pre[index++];
    Node *root = new Node(element);
    int position = findposition(in, inorderstart, inorderend, element, n);

    root->left = solve(in, pre, index, inorderstart, position - 1, n);
    root->right = solve(in, pre, index, position + 1, inorderend, n);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    int preorderindex = 0;
    Node *ans = solve(in, pre, preorderindex, 0, n - 1, n);
    return ans;
}
// Function to display the constructed binary tree (postorder traversal)
void displayInorder(Node* node)
{
    if (node == NULL)
        return;
    
    displayInorder(node->left);
    displayInorder(node->right);
    cout << node->data << " ";
}
int main()
{
    int n = 4;
    int in[] = {1, 6, 8, 7};
    int pre[] = {1, 6, 7, 8};
    Node* finalAnswer = buildTree(in, pre, n);
    
    // Display the constructed binary tree (inorder traversal)
    displayInorder(finalAnswer);
    
    return 0;

}