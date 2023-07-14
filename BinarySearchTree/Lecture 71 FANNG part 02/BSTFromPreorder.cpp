#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(BinaryTreeNode* root) {
    if (root == NULL) {
        return;
    }
    queue<BinaryTreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode* temp = q.front();
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

BinaryTreeNode* solve(vector<int>& preorder, int mini, int maxi, int& i) {
    if (i >= preorder.size()) {
        return nullptr;
    }
    if (preorder[i] > maxi || preorder[i] < mini) {
        return nullptr;
    }
    BinaryTreeNode* root = new BinaryTreeNode(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);
    return root;
}

BinaryTreeNode* preorderToBST(vector<int>& preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int index = 0;
    return solve(preorder, mini, maxi, index);
}

int main() {
    // Example usage of the code
    vector<int> preorder = {4, 2, 1, 3, 6, 5, 7};
    BinaryTreeNode* root = preorderToBST(preorder);
    levelOrderTraversal(root);

    return 0;
}
