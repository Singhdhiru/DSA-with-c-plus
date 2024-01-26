#include <iostream>
#include <vector>
using namespace std;

// Define the TreeNode structure
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Approach-1 (Simple and straight forward)
// T.C : O(n)
// S.C : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))
int result = 0;
void solve(TreeNode *root, vector<int> &count)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    count[root->val]++;
    // leaf Node
    if (root->left == NULL && root->right == NULL)
    {
        int oddfreq = 0;
        for (int i = 0; i < count.size(); i++)
        {
            if (count[i] % 2 != 0)
            { // odd number baar aaya hi
                oddfreq++;
            }
        }
        // pure count array mai only ak baar odd freq hona chahiye
        if (oddfreq <= 1)
        {
            result += 1;
        }
    }
    solve(root->left, count);
    solve(root->right, count);
    // ak path per chale gaye waps aate time use count array mai -- kar do
    count[root->val]--;
}
int pseudoPalindromicPaths(TreeNode *root)
{
    vector<int> count(10, 0);
    solve(root, count);
    return result;
}

// Approach-2 (Using bit magic)
// T.C : O(n)
// S.C : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))
int result = 0;

void solve(TreeNode *root, int temp)
{
    if (root != NULL)
    {

        temp = temp ^ (1 << root->val);

        if (root->left == NULL && root->right == NULL)
        {
            if ((temp & (temp - 1)) == 0)
            { // Make sure to put (temp & (temp - 1)) entirely in bracket because precedence of  == is high
                result++;
            }
        }

        solve(root->left, temp);
        solve(root->right, temp);
    }
}

int pseudoPalindromicPaths(TreeNode *root)
{

    solve(root, 0);
    return result;
}
int main()
{
    // Create a sample tree for testing
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);

    // Call your pseudoPalindromicPaths function and display the result
    int result = pseudoPalindromicPaths(root);
    std::cout << "Number of pseudo-palindromic paths: " << result << std::endl;

    // Cleanup: Release allocated memory
    // Note: You should free the memory allocated for the tree in a real program
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
