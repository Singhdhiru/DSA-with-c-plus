#include <iostream>
#include <vector>

using namespace std;

void printCombination(int a[], int n, vector<string> &ans, vector<string> &keypad, int idx, string temp)
{

    if (idx == n)
    {
        ans.push_back(temp);
        return;
    }

    int number = a[idx];
    string mapping = keypad[number];
    for (int i = 0; i < mapping.size(); i++)
    {
        temp.push_back(mapping[i]);
        printCombination(a, n, ans, keypad, idx + 1, temp);
        temp.pop_back();
    }
}
// Function to find list of all words possible by pressing given numbers.
vector<string> possibleWords(int a[], int N)
{
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    printCombination(a, N, ans, keypad, 0, "");
    return ans;
}

#include <iostream>

int main()
{
    int a[] = {2, 3, 4}; // You can change the array as needed
    int N = sizeof(a) / sizeof(a[0]);

    // Calling the possibleWords function
    vector<string> result = possibleWords(a, N);

    // Displaying the result
    cout << "List of possible words:\n";
    for (const string &word : result)
    {
        cout << word << " ";
    }

    return 0;
}
