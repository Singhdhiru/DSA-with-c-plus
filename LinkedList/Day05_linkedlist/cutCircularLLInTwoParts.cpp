#include <iostream>
using namespace std;

// Define the structure of a node in a circular linked list
class Node {
    public:
    int data;
    Node* next;
    Node(int val) {
        this->data = val;
        this->next = NULL;
    }
};

// Function to convert a single circular linked list into two circular linked lists
void convertToLists(Node* head, Node** list1, Node** list2) {
    if (head == NULL) return;

    Node* curr = head;
    int pos = 1;
    do {
        // Create a new node with the same value as the current node in the original list
        Node* newNode = new Node(curr->data);

        // Append the new node to list1
        if (*list1 == NULL) {
            *list1 = newNode;
            newNode->next = *list1;
        } else {
            newNode->next = (*list1)->next;
            (*list1)->next = newNode;
            *list1 = newNode;
        }

        // Append the new node to list2 if the current position is even
        if (pos % 2 == 0) {
            if (*list2 == NULL) {
                *list2 = newNode;
                newNode->next = *list2;
            } else {
                newNode->next = (*list2)->next;
                (*list2)->next = newNode;
                *list2 = newNode;
            }
        }

        // Move to the next node in the original list
        curr = curr->next;
        pos++;
    } while (curr != head);
}

// Function to print a circular linked list
void printList(Node* head) {
    if (head == NULL) return;

    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

// Driver code to test the implementation
int main() {
    // Create a sample circular linked list with 6 nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = head;
    printList(head);

    // Call the function to convert the original list into two lists
    Node* list1 = NULL;
    Node* list2 = NULL;
    convertToLists(head, &list1, &list2);

    // Print the two resulting lists
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    return 0;
}
