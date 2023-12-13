#include <iostream>
#include <vector>
using namespace std;

void calcSubset(vector<int>& A, vector<int>& subset, int index)
{
    // Print the current subset
    for (int i = 0; i < subset.size(); i++)
        cout << subset[i] << " ";
    cout << endl;

    // Generate subsets by recursively including and
    // excluding elements
    for (int i = index; i < A.size(); i++) {
        // Include the current element in the subset
        subset.push_back(A[i]);

        // Recursively generate subsets with the current
        // element included
        calcSubset(A, subset, i + 1);

        // Exclude the current element from the subset
        // (backtracking)
        subset.pop_back();
    }
}

void subsets(vector<int>& A)
{
    vector<int> subset;
    int index = 0;
    calcSubset(A, subset, index);
}

// Driver code
int main()
{
    vector<int> array = { 1, 2, 3 };
    cout << "Subsets:" << endl;
    subsets(array);

    return 0;
}
