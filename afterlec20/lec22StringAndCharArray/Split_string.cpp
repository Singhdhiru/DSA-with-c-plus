// using custom delimeter
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(const string &str, char delimiter)
{
    vector<string> result;
    stringstream ss(str);
    string item;

    while (getline(ss, item, delimiter))
    {
        result.push_back(item);
    }

    return result;
}

int main()
{
    string s = "item1;item2;item3";
    char delimiter = ';';

    vector<string> items = split(s, delimiter);

    for (const auto &item : items)
    {
        cout << item << endl;
    }

    return 0;
}