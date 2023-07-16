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

void convertTreeToSortedDLL(Node *root, Node *&head)
{
    if (!root)
        return;

    convertTreeToSortedDLL(root->right, head);

    root->right = head;
    if (head)
        head->left = root;

    head = root;

    convertTreeToSortedDLL(root->left, head);
}

Node *mergeSDLL(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                head1 = head1->right;
                tail = head;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = tail->right;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                head2 = head2->right;
                tail = head;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = tail->right;
                head2 = head2->right;
            }
        }
    }

    if (head1)
    {
        tail->right = head1;
        head1->left = tail;
    }
    else if (head2)
    {
        tail->right = head2;
        head2->left = tail;
    }

    return head;
}

int countNodes(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->right;
    }
    return count;
}

Node *convertDLLToBST(Node *&head, int n)
{
    if (n <= 0 || head == NULL)
        return NULL;

    Node *left = convertDLLToBST(head, n / 2);
    Node *root = head;
    root->left = left;
    head = head->right;
    root->right = convertDLLToBST(head, n - n / 2 - 1);

    return root;
}

Node *mergeBST(Node *root1, Node *root2)
{
    if (!root1)
        return root2;
    if (!root2)
        return root1;

    Node *head1 = NULL;
    convertTreeToSortedDLL(root1, head1);
    head1->left = NULL;

    Node *head2 = NULL;
    convertTreeToSortedDLL(root2, head2);
    head2->left = NULL;

    Node *head = mergeSDLL(head1, head2);

    int n = countNodes(head);

    return convertDLLToBST(head, n);
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
    cout << "Enter the data to create BST 1 (-1 to stop): ";
    takeInput(root1);
    cout << endl;

    cout << "Level order traversal of BST 1: " << endl;
    levelOrderTraversal(root1);
    cout << endl;

    Node *root2 = NULL;
    cout << "Enter the data to create BST 2 (-1 to stop): ";
    takeInput(root2);
    cout << endl;

    cout << "Level order traversal of BST 2: " << endl;
    levelOrderTraversal(root2);
    cout << endl;

    cout << "Merged BST: " << endl;
    Node *finalAns = mergeBST(root1, root2);
    levelOrderTraversal(finalAns);
    cout << endl;

    return 0;
}


// T.C ->>> O(N+m);
// s.c ->>O(H1+H2)->>>>> optimized