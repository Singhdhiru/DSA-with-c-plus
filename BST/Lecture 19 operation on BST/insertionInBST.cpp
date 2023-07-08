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
void inorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}
Node*  insertIntoBst(Node* root, int data){
    // base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data> root->data){
        //left part mai insert karna h
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

    cout<<"inorder traversal:";
    inorder(root);
    cout<<endl;

    cout<<"preorder traversal:";
    preorder(root);
    cout<<endl;

    cout<<"postorder traversal:";
    postorder(root);
    return 0;
}