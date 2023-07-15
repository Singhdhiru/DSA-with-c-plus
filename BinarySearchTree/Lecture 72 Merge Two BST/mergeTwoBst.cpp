#include <iostream>
#include <queue>
#include <vector>
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
            cout << endl;
            if (!q.empty())
            {
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

void inorder(Node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArray(vector<int> &a, vector<int> &b)
{
    vector<int> ans(a.size() + b.size());
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[k] = a[i];
            k++;
            i++;
        }
        else
        {
            ans[k] = b[j];
            k++;
            j++;
        }
    }

    while (i < a.size())
    {
        ans[k] = a[i];
        k++;
        i++;
    }

    while (j < b.size())
    {
        ans[k] = b[j];
        k++;
        j++;
    }

    return ans;
}

Node *inorderToBst(int s, int e, vector<int> &mergeArr)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    Node *root = new Node(mergeArr[mid]);
    root->left = inorderToBst(s, mid - 1, mergeArr);
    root->right = inorderToBst(mid + 1, e, mergeArr);

    return root;
}

Node *merge(Node *root1, Node *root2)
{
    vector<int> bst1;
    vector<int> bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    vector<int> mergeArr = mergeArray(bst1, bst2);

    int s = 0;
    int e = mergeArr.size() - 1;

    return inorderToBst(s, e, mergeArr);
}

Node *insertIntoBst(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBst(root->right, data);
    }
    else
    {
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
    Node *root1 = NULL;
    cout << "Enter the data to create BST (-1 to stop): ";
    takeInput(root1);
    cout << endl;

    cout << "Level order traversal of BST 1: " << endl;
    levelOrderTraversal(root1);
    cout << endl;

    Node *root2 = NULL;
    cout << "Enter the data to create BST (-1 to stop): ";
    takeInput(root2);
    cout << endl;

    cout << "Level order traversal of BST 2: " << endl;
    levelOrderTraversal(root2);
    cout << endl;

    cout << "Merged BST: " << endl;
    Node *finalAns = merge(root1, root2);
    levelOrderTraversal(finalAns);
    cout << endl;

    return 0;
}

// T.C ->>> O(N+m);
// s.c ->>O(n+m)->>>>> optimized in method 2;