#include <iostream>
using namespace std;
// Function to find the maximum occurring character in a string.
char getMaxOccuringChar(string s)
{
    // make array for characters count
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        // access first element
        char ch = s[i];
        int index = 0;
        // character ka uska position find karna
        index = ch - 'a';
        arr[index]++;
    }
    // find maximum occurence of characters
    int maxi = -1;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }
    return 'a' + ans;
}
int main()
{
    string s;
    cout << "enter the string ->";
    cin >> s;
    cout << "maximum occuring character in string->" << getMaxOccuringChar(s) << endl;
    return 0;
}