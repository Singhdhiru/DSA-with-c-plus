#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void iterativePreorder(Node* root){
    // base case
    if(root == NULL){
        return ;
    }

    // create stack and push the root of the tree
    stack<Node*>st;
    st.push(root);
    /*
    pop the element one by one 
    ->print it
    ->push its right 
    ->push its left
    ! note-> that right child push first so that left is processed first
    */
    while(!st.empty()){
        struct Node* temp = st.top();
        cout<<temp->data<<" ";
        st.pop();

        if(temp->right){
            st.push(temp->right);
        }
        if(temp->left)
        st.push(temp->left);
    }
}

void iterativeInorder(Node* root) {
    stack<Node*> s;
    Node* curr = root;

    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        cout << curr->data << " ";

        curr = curr->right;
    }
}


void printTree(Node* node) {
    if (node == NULL)
        return;

    // Print the value of the current node
    cout << node->data << " ";

    // Recursively print the left and right subtrees
    printTree(node->left);
    printTree(node->right);
}
int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right  = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // print the values
    printTree(root);
    cout<<endl;

    cout<<"print iterative preorder traversal=>> ";
    iterativePreorder(root);

    cout<<endl<<"iterative inorder traversal ->>";
    iterativeInorder(root);
    
    return 0;
}