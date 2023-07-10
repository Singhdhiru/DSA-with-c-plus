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
pair<int, int> predecessorSuccessor(Node* root, int key)
{
    // Find key
    Node* temp = root;
    int pred = -1;
    int succ = -1;

    while (temp != NULL && temp->data != key) {
        if (temp->data > key) {
            succ = temp->data;
            temp = temp->left;
        }
        else {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // Key not found
    if (temp == NULL) {
        return make_pair(-1, -1);
    }

    // Pred and succ
    // Pred
    if (temp->left != NULL) {
        Node* leftTree = temp->left;
        while (leftTree->right != NULL) {
            leftTree = leftTree->right;
        }
        pred = leftTree->data;
    }

    // Succ
    if (temp->right != NULL) {
        Node* rightTree = temp->right;
        while (rightTree->left != NULL) {
            rightTree = rightTree->left;
        }
        succ = rightTree->data;
    }

    pair<int, int> ans = make_pair(pred, succ);
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

    int key ;
    cout<<"enetr the key-> ";
    cin>>key;
    cout<<endl;
    cout << "Predecessor of given Node: " << predecessorSuccessor(root, key).first << endl;
    cout << "Successor of given Node: " << predecessorSuccessor(root, key).second << endl;

    return 0;
}