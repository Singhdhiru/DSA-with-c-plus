#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            // purana level complete traversal ho chuka hi
            cout<<endl;
            if(!q.empty()){
                // queue still has some childernels
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
int solve(Node* root, int& i, int k){
    // base case
    if(root == NULL){
        return -1;
    }
    // L
    int left = solve(root->left, i, k);
    if(left != -1){
        return left;
    }
    // N
    i++;
    if(i == k){
        return root->data;
    }
    // R
    return solve(root->right, i, k);
}

int kthSmallest(Node* root, int k) {
    int i = 0; // Initialize i to 0
    int ans = solve(root, i , k);
    return ans;
}
Node*  insertIntoBst(Node* root, int data){
    // base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data> root->data){
        //right part mai insert karna h
        root->right = insertIntoBst(root->right, data);
    }
    else{
        // left part mia insert karna hi
        root->left = insertIntoBst(root->left, data);
    }
    return root;
}
void takeInput(Node*& root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBst(root, data);
        cin>>data;
    }
}
int main() {
    Node* root = NULL;
    cout << "Enter the data to create BST (-1 to stop): ";
    takeInput(root);
    cout << endl;

    cout << "Level order traversal: "<<endl;
    levelOrderTraversal(root);
    cout << endl;

    cout<<"k th smallest element in the BSt:"<<kthSmallest(root, 3)<<endl;
    return 0;
}