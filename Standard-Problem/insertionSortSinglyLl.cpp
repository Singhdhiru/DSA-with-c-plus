#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *insertionSortLL(Node *head_ref)
{
    if (!head_ref)
    {
        return nullptr;
    }

    Node *dummy = new Node(-1);
    Node *head = head_ref; // Add a pointer to the current head of the sorted list

    while (head)
    {
        Node *headNext = head->next;
        Node *temp = dummy;

        while (temp->next && head->data >= temp->next->data)
        {
            temp = temp->next;
        }

        head->next = temp->next;
        temp->next = head;
        head = headNext;
    }

    return dummy->next;
}

int main()
{
    // Sample usage of the insertionSortLL function
    Node *head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(2);

    Node *current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    // Call the insertionSortLL function
    head = insertionSortLL(head);

    current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}
