#include <iostream>

using namespace std;

/*
    *MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ePTZbVoJ6FI
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/flip-equivalent-binary-trees
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//* Approach - Simple Recursion
// T.C : ~O(4*n)
// S.C : O(n) system stack space because of Recursion
class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return true;

        if (root1 == NULL || root2 == NULL)
        {
            return false;
        }

        if (root1->val == root2->val)
        {
            return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ||
                   flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        }

        return false;
    }
};

int main()
{
    // Create two binary trees
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(2);

    // Create an instance of Solution
    Solution solution;

    // Check if the two trees are flip equivalent
    bool result = solution.flipEquiv(root1, root2);

    // Output the result
    cout << (result ? "The trees are flip equivalent." : "The trees are not flip equivalent.") << endl;

    // Clean up memory (optional)
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}