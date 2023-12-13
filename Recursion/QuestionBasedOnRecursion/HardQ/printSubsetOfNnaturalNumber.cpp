#include <iostream>
#include <vector>

using namespace std;

void printSubsets(const vector<int> &subset)
{
    for (int i = 0; i < subset.size(); i++)
    {
        cout << subset[i] << " ";
    }
    cout << endl;
}

void findSubsets(int n, vector<int> &subset)
{
    if (n == 0)
    {
        printSubsets(subset);
        return;
    }

    findSubsets(n - 1, subset);
    subset.push_back(n);
    findSubsets(n - 1, subset);
    subset.pop_back();
}

int main()
{
    int n = 3;
    vector<int> subset;
    findSubsets(n, subset);

    return 0;
}
