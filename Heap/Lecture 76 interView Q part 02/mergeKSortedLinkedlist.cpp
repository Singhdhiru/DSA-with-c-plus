#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return (a->data > b->data);
    }
};

// Function to merge K sorted linked lists.
Node* mergeKLists(Node* arr[], int K) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    
    // Step 01: Push the heads of all K linked lists into the minHeap
    for (int i = 0; i < K; i++) {
        if (arr[i] != NULL) {
            minHeap.push(arr[i]);
        }
    }

    // Initialize head and tail pointers for the result linked list
    Node* head = NULL;
    Node* tail = NULL;

    while (!minHeap.empty()) {
        // Step 02: Pop the smallest element from the minHeap
        Node* top = minHeap.top();
        minHeap.pop();

        // Push the next element from the popped list into the minHeap
        if (top->next != NULL) {
            minHeap.push(top->next);
        }

        // If head is NULL, the answer LL is empty
        if (head == NULL) {
            head = top;
            tail = top;
        } else {
            // Insert at the tail of the LL
            tail->next = top;
            tail = top;
        }
    }

    return head;
}

// Utility function to print a linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    // Create three sorted linked lists
    Node* list1 = new Node(1);
    list1->next = new Node(4);
    list1->next->next = new Node(5);

    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    Node* list3 = new Node(2);
    list3->next = new Node(6);

    // Create an array of pointers to the linked lists
    Node* arr[] = {list1, list2, list3};
    int K = 3;

    Node* mergedList = mergeKLists(arr, K);

    std::cout << "Merged Linked List: ";
    printLinkedList(mergedList);

    // Free memory
    // delete mergedList; // Note that delete will recursively delete the entire merged linked list
    return 0;
}
