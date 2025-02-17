
    //  YOUTUBE LINK :  https://www.youtube.com/watch?v=G5c1wM3Kpuw&list=PLpIkg8OmuX-K23LhcamOcDlTBisiNJy5E&index=4
    // Company Tags    :  Accolite, Amazon, Microsoft
    // Leetcode Link   :  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// ToDo Basic Approach -1 
//* Time Complexity -> o(n^2)
//* Space complexity -> O(n)
class Solution {
public:
    //* Find the position of root in inorder vector take o(n) time complexity always we can reduce this time complexity by using map
    int findPosition(int &root, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            if (inorder[i] == root) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int &idx) {
        if (start > end) {
            return NULL;
        }

        //* preorder ka first element hi root hoga(preorder Traversal -> ROOT, Left, Right).*/
        int val = preorder[idx++];
        //* root ka position in inorder vector
        int position = findPosition(val, inorder);

        TreeNode* root = new TreeNode(val);
        root->left = solve(preorder, inorder, start, position - 1, idx);
        root->right = solve(preorder, inorder, position + 1, end, idx);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        TreeNode* ans = solve(preorder, inorder, 0, inorder.size() - 1, idx);
        return ans;
    }
};
//* Optimal Approach -2
//*Optimized approach by using map to find index of root in inorder array
class Solution_Map {
public:
    unordered_map<int, int> mp;
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int l, int r, int& idx) {
        if(l > r)
            return NULL;
        
        int rootVal = preorder[idx];
        idx++;
        int i = mp[rootVal];
        
        TreeNode* root = new TreeNode(rootVal);
        root->left     = construct(preorder, inorder, l, i-1, idx);
        root->right    = construct(preorder, inorder, i+1, r, idx);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mp.clear();
        int n = preorder.size();
        for(int i = 0; i<n; i++) {
            mp[inorder[i]] = i;
        }
        
        int idx = 0;
        return construct(preorder, inorder, 0, n-1, idx);
    }
};
int main() {
    //TODO:  Example usage:
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    //* Build new tree from inorder and preorder 
    TreeNode* root = sol.buildTree(preorder, inorder);
    //* If you want to check right tree are build form then find inoerder traversall of new tree and compare with inorder vector.
    cout<<"Find Inorder "<<endl;
    return 0;
}
