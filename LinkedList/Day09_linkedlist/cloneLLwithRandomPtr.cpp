#include <unordered_map>

struct Node
{
    int val;
    Node *next;
    Node *random;

    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

Node *cloneLinkedList(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    std::unordered_map<Node *, Node *> copies;
    Node *curr = head;
    while (curr != nullptr)
    {
        copies[curr] = new Node(curr->val);
        curr = curr->next;
    }
    curr = head;
    while (curr != nullptr)
    {
        copies[curr]->next = copies[curr->next];
        copies[curr]->random = copies[curr->random];
        curr = curr->next;
    }
    return copies[head];
}
