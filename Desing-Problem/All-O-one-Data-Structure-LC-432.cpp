#include <iostream>
#include <unordered_map>
#include <list>
#include <string>

using namespace std;

// Approach (Using map + dll)
// T.C : O(1)
// S.C : O(n), map stores n strings
class AllOne {
private:
    // Doubly Linked List node to store count and a set of strings with that count
    struct Node {
        int count;
        list<string> keys; // You should use an unordered_set<string> here because it will have Amortized O(1) time complexity for erase() function.
        Node *prev, *next;
        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };

    // Hash map to store key -> count
    unordered_map<string, Node*> mp;

    // Head and tail pointers for the doubly linked list
    Node *head, *tail;

    // Add a new node with count `c` after node `prevNode`
    Node* addNodeAfter(Node *prevNode, int count) {
        Node *newNode = new Node(count);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if (prevNode->next) {
            prevNode->next->prev = newNode;
        }
        prevNode->next = newNode;
        if (tail == prevNode) {
            tail = newNode;
        }
        return newNode;
    }

    // Remove the node from the doubly linked list
    void removeNode(Node *node) {
        node->prev->next = node->next;
        if (node->next) {
            node->next->prev = node->prev;
        }
        if (tail == node) {
            tail = node->prev;
        }
        delete node;
    }

public:
    AllOne() {
        // Initialize head and tail dummy nodes for the doubly linked list
        head = new Node(0);
        tail = head;
    }

    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            // Key doesn't exist, add it to the list after the head with count 1
            if (head->next == nullptr || head->next->count != 1) {
                addNodeAfter(head, 1);
            }
            head->next->keys.push_front(key);
            mp[key] = head->next;
        } else {
            // Key exists, move it to the next count
            Node *curNode = mp[key];
            int curCount = curNode->count;
            if (curNode->next == nullptr || curNode->next->count != curCount + 1) {
                addNodeAfter(curNode, curCount + 1);
            }
            curNode->next->keys.push_front(key);
            mp[key] = curNode->next;
            curNode->keys.remove(key);
            if (curNode->keys.empty()) {
                removeNode(curNode);
            }
        }
    }

    void dec(string key) {
        Node *curNode = mp[key];
        int curCount = curNode->count;

        // Remove the key if count becomes zero
        curNode->keys.remove(key);
        if (curCount == 1) {
            mp.erase(key);
        } else {
            // Move it to the previous count
            if (curNode->prev == head || curNode->prev->count != curCount - 1) {
                addNodeAfter(curNode->prev, curCount - 1);
            }
            curNode->prev->keys.push_front(key);
            mp[key] = curNode->prev;
        }

        // Remove the current node if it has no more keys
        if (curNode->keys.empty()) {
            removeNode(curNode);
        }
    }

    string getMaxKey() {
        return (tail == head) ? "" : tail->keys.front();
    }

    string getMinKey() {
        return (head->next == nullptr) ? "" : head->next->keys.front();
    }
};

int main() {
    AllOne allOne;

    allOne.inc("hello");
    allOne.inc("world");
    allOne.inc("hello");

    cout << "Max Key: " << allOne.getMaxKey() << endl; // Should print "hello"
    cout << "Min Key: " << allOne.getMinKey() << endl; // Should print "world"

    allOne.dec("hello");
    
    cout << "Max Key after decrementing hello: " << allOne.getMaxKey() << endl; // Should print "hello"
    
    allOne.dec("hello");
    
    cout << "Min Key after decrementing hello: " << allOne.getMinKey() << endl; // Should print "world"
    
    allOne.dec("world");
    
    cout << "Max Key after decrementing world: " << allOne.getMaxKey() << endl; // Should print ""
    
    return 0;
}