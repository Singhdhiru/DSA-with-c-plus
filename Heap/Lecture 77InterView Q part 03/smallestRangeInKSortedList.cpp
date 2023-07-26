#include <bits/stdc++.h>
using namespace std;

const int N = 1000; // Assuming N is a constant value for the number of columns

pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k) {
    class Node {
    public:
        int data;
        int row;
        int col;

        Node(int d, int r, int c) {
            data = d;
            row = r;
            col = c;
        }
    };

    class Compare {
    public:
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
    };

    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < k; i++) {
        int elem = KSortedArray[i][0];
        mini = min(mini, elem);
        maxi = max(maxi, elem);
        pq.push(new Node(elem, i, 0));
    }

    int start = mini, end = maxi;

    while (!pq.empty()) {
        Node* temp = pq.top();
        pq.pop();
        mini = temp->data;

        if (maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        if (temp->col + 1 < n) {
            maxi = max(maxi, KSortedArray[temp->row][temp->col + 1]);
            pq.push(new Node(KSortedArray[temp->row][temp->col + 1], temp->row, temp->col + 1));
        } else {
            break;
        }
    }

    return make_pair(start, end);
}

int main() {
    int KSortedArray[][N] = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };
    int n = 4; // Number of columns
    int k = 3; // Number of rows

    pair<int, int> result = findSmallestRange(KSortedArray, n, k);
    cout << "Smallest Range: " << result.first << " to " << result.second << endl;

    return 0;
}
