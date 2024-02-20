#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // purana level complete traversal ho chuka hi
            cout << endl;
            if (!q.empty())
            {
                // queue still has some childernels
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder(Node* root, vector<int>&in){
    if(root == NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
// ? Approach 1 -> using Extra space 
Node* flatten(Node* root)
{
    vector<int> inorderVal;
    // inorder ko store kr liya
    inorder(root, inorderVal);
    int n = inorderVal.size();
    if (n == 0) {
        return nullptr;
    }
    Node* newRoot = new Node(inorderVal[0]);
    Node* curr = newRoot;

    // step 2;
    for(int i=1; i<n; i++){
        Node* temp = new Node(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    // 3rd step last ke element ka right anf left dono NULL kar dena hi
    curr->left = NULL;
    curr->right = NULL;
    return newRoot;
}
// * Approch 2 -> Fllowup Question at gfg ->>   without using any extra storage
/*
MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=NzXtnzQTouk
    Company Tags                : Amazon, Adobe
    GFG Link                    : https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1
*/
//T.C : O(n^2)
//S.C : Auxiliary Space is O(1) and Stack Space due to recursion is O(n)
Node* flattenBst(Node* root){
    // * base case
    if(root == NULL){
        return NULL;
    }
    // ? root ke left ko pahle flat kar lenge
    Node* head = flattenBst(root->left);
    // ? root pahle left mai point kr raha tha ab uska left ko NULL point kra dunga 
    root->left = NULL;
    // ? root ke right ko uske right mai flatt kar ke aayega use link kr dunga
    root->right = flattenBst(root->right);

    // ? left flat ho chuka aur head ko piont bhi kr raha ham ham left flat mai traverse kar ke tail per jaunga aur tail ke right ko root per point kra dunga

    if(head){
        Node* temp = head;
        while(temp && temp->right){
            temp = temp->right;
        }
        temp->right = root;
    }
    else{
        //? If head is NULL, root becomes the head ->> jab rooot ke left mai kuch ho hina
        // head ko root bna dunga aur root kp right flat se add kr dunga
        head = root;
    }
    return head;
}
Node *insertIntoBst(Node *root, int data)
{
    // base case
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        // left part mai insert karna h
        root->right = insertIntoBst(root->right, data);
    }
    else
    {
        // left part mia insert karna hi
        root->left = insertIntoBst(root->left, data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}
int main()
{
    Node *root = NULL;
    cout << "Enter the data to create BST (-1 to stop): ";
    takeInput(root);
    cout << endl;

    cout << "Level order traversal: " << endl;
    levelOrderTraversal(root);
    cout << endl;

    // Flatten the binary tree
    Node* flattenedRoot = flattenBst(root);

    // Print the flattened tree
    cout << "Flattened tree: " << endl;
    levelOrderTraversal(flattenedRoot);
    cout << endl;

    return 0;
}
