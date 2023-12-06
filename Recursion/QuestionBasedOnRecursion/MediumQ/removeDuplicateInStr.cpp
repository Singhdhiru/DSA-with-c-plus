#include <iostream>
#include <vector>
using namespace std;

vector<bool> present(26);
string removeDuplicates(const string &str, int idx)
{
    if (idx == str.length())
    {
        return "";
    }

    char curr = str.at(idx);

    if (present[curr - 'a'])
    {
        return removeDuplicates(str, idx + 1);
    }
    else
    {
        present[curr - 'a'] = true;
        return curr + removeDuplicates(str, idx + 1);
    }
}
int main()
{
    string str = "abcadbcefghabi";
    cout << removeDuplicates(str, 0) << endl;
    return 0;
}