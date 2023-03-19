#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *getMiddle(Node *head)
{
    // ? use slow and fast pointer to find the middle of linkrdlist
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node *reverse(Node *temp)
{
    Node *curr = temp;
    Node *pre = NULL;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}
bool checkPalnidrome(Node *head)
{
    // ? ak hi node ho ak bhi na ho
    if (head == NULL && head->next == NULL)
    {
        return true;
    }
    // ? step ->01 find the middle of linkednlist
    Node *middle = getMiddle(head);
    Node *temp = middle->next;

    // ? step -->>02 reverse the linked list after the middle
    middle->next = reverse(temp);

    //?step3 - Compare both halves
    Node *head1 = head;
    Node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head2->data != head1->data)
        {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // * step ->>04 (optional) -> step 2 mai jo reverse kiye hi use phie se sahi order mai kar denge
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *node2 = new Node(12);
    head->next = node2;
    Node *node3 = new Node(12);
    head->next->next = node3;
    Node *node4 = new Node(101);
    head->next->next->next = node4;
    print(head);

    // ? check Linkedlist is palindrome or not
    if (checkPalnidrome(head))
    {
        cout << "linked list is palindrome" << endl;
    }
    else
    {
        cout << "not palindrome" << endl;
    }
    return 0;
}