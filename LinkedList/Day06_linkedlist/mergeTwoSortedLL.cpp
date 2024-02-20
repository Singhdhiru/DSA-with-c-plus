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

//*Approach-1 (Recursion)
//T.C : O(m+n) - total number of nodes
//S.C : O(1) (ignoring recursive stack space)
Node *solve(Node *list1, Node *list2)
{
    // ? base case
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    Node *result;

    if (list1->data <= list2->data)
    {
        // ? jo val small ho use res mai daal do aur usi list ke next mai chale jaoo
        result = list1;
        result->next = solve(list1->next, list2);
    }
    else
    {
        result = list2;
        result->next = solve(list1, list2->next);
    }

    return result;
}

//*Approach-2 (Iterative)
//T.C : O(m+n) - total number of nodes
//S.C : O(1)
Node *mergeLists(Node *first, Node *second)
{
    if (first->next == NULL)
    {

        first->next = second;

        return first;
    }

    Node *curr1 = first;

    Node *next1 = curr1->next;

    Node *curr2 = second;

    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {

        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {

            curr1->next = curr2;

            next2 = curr2->next;

            curr2->next = next1;

            curr1 = curr2;

            curr2 = next2;
        }

        else
        {

            curr1 = next1;

            next1 = next1->next;

            if (next1 == NULL)
            {

                curr1->next = curr2;

                return first;
            }
        }
    }

    return first;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head1 = new Node(1);
    // head1->data = 1;
    head1->next = new Node(2);
    // head1->next->data = 3;
    head1->next->next = new Node(7);
    // head1->next->next->data = 5;
    head1->next->next->next = NULL;

    Node *head2 = new Node(1);
    // head2->data = 2;
    head2->next = new Node(1);
    head2->next->next = new Node(9);
    // head2->next->next->data = 6;
    head2->next->next->next = NULL;

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);
    // ? iterative call
    // Node *mergedHead = mergeLists(head1, head2);

    // ? recursive call
    Node *mergedHead = solve(head1, head2);

    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}
