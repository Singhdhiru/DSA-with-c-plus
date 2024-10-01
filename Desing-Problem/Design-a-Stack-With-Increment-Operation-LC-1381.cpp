#include <iostream>
#include <vector>
using namespace std;

// Approach (Using Array + Lazy Propagation)
// T.C : push : O(1), pop : O(1), increment : O(1)
// S.C : O(maxSize)

class CustomStack {
public:
    vector<int> st;
    vector<int> increments;
    int n;

    CustomStack(int maxSize) {
        n = maxSize;
    }

    void push(int x) {
        if (st.size() < n) {
            st.push_back(x);
            increments.push_back(0);
        }
    }

    int pop() {
        if (st.size() == 0) {
            return -1;
        }
        int idx = st.size() - 1; // top element index
        if (idx > 0) {
            increments[idx - 1] += increments[idx];
        }
        int top_val = st[idx] + increments[idx];
        st.pop_back();
        increments.pop_back();
        return top_val;
    }

    void increment(int k, int val) {
        // Note that input might contain K which is greater than st.size()
        int idx = min(k, (int)st.size()) - 1;
        if (idx >= 0) {
            increments[idx] += val;
        }
    }
};

int main() {
    CustomStack customStack(5); // Create a CustomStack with a maximum size of 5

    customStack.push(1);
    customStack.push(2);
    cout << "Pop: " << customStack.pop() << endl; // Should return 2
    customStack.push(3);
    customStack.push(4);
    customStack.increment(2, 100); // Increment the first 2 elements by 100
    cout << "Pop: " << customStack.pop() << endl; // Should return 104
    cout << "Pop: " << customStack.pop() << endl; // Should return 103
    cout << "Pop: " << customStack.pop() << endl; // Should return 1
    cout << "Pop: " << customStack.pop() << endl; // Should return -1 (stack is empty)

    return 0;
}