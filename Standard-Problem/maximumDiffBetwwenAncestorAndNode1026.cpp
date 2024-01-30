/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=cvekQzmBdcs
    Company Tags                : Google, Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
*/

/************************************************************ C++ ***************************************************************************/
// Approach-1 (Brute Force) - O(n^2) - n = number of nodes in the Tree
/*
    Just simply take a root, find all the differences of it from its childres and find max one
    Again go to root->left and do the same as above
    Again go to root->right and do the same as above
*/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    int maxDiff;

    void findMaxUtil(TreeNode *root, TreeNode *child)
    {
        if (!root || !child)
            return;

        maxDiff = max(maxDiff, abs(root->val - child->val));

        findMaxUtil(root, child->left);
        findMaxUtil(root, child->right); //? root ko fix kar diya hu
    }

    void findMaxDiff(TreeNode *root)
    {
        if (!root || !root->left && !root->right)
            return;

        // Find max differences of this root with all its children
        findMaxUtil(root, root->left);
        findMaxUtil(root, root->right);

        // firther move left and right
        findMaxDiff(root->left);
        findMaxDiff(root->right);
    }

    int maxAncestorDiff_brute_force(TreeNode *root)
    {
        maxDiff = INT_MIN;

        findMaxDiff(root);

        return maxDiff;
    }

// Approach-2
// Optimal (O(n)) using min and max value for |min-max|
    int findMaxDiff(TreeNode *root, int minV, int maxV)
    {
        if (!root)
            return abs(minV - maxV);

        minV = min(root->val, minV);
        maxV = max(root->val, maxV);

        int l = findMaxDiff(root->left, minV, maxV);
        int r = findMaxDiff(root->right, minV, maxV);

        return max(l, r);
    }

    int maxAncestorDiff(TreeNode *root)
    {
        int minV = root->val;
        int maxV = root->val;

        return findMaxDiff(root, minV, maxV);
    }

    
int main() {
    // Create a sample binary tree for testing
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    // Call the maxAncestorDiff function
    int result = maxAncestorDiff(root);

    // Display the result
    cout << "Maximum Ancestor Difference: " << result << endl;

    // Clean up the allocated memory (optional)
    // Note: You may want to implement a function to delete the tree nodes recursively
    // for a real-world scenario.
    delete root->right->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}