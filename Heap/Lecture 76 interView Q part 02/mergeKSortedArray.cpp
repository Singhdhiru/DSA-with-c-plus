#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node {
public:
    int data;
    int i;
    int j;
public:
    Node(int data, int row, int col) {
        this->data = data;
        i = row;
        j = col;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return (a->data > b->data);
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    // Min Heap
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    // Push first element of each array.
    for (int i = 0; i < k; i++) {
        Node* temp = new Node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }
    vector<int> ans;

    // top ko ans array mai daaloo and next element ko minheap mai push kro
    while (minHeap.size() > 0) {
        Node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        // next element ko push kro
        int i = temp->i;
        int j = temp->j;
        if (j + 1 < kArrays[i].size()) {
            Node* next = new Node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }

    return ans;
}

int main() {
    // Example usage of the mergeKSortedArrays function
    vector<vector<int>> kArrays = {{1, 5, 9}, {3, 6, 8}, {2, 4, 7}};
    int k = 3;
    vector<int> mergedArray = mergeKSortedArrays(kArrays, k);

    // Output the merged array
    cout << "Merged Array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
