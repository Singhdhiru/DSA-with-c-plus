#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

string firstNonReapeting(string A)
{
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";
    for (int i = 0; i < A.size(); i++)
    {
        char ch = A[i];
        //  increase count
        count[ch]++;
        // queue mai push kr do
        q.push(ch);
        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                // reapeting charcter
                q.pop();
            }
            else
            {
                // non repeating character
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}
int main()
{
    string A = "aabc";
    string  finalAns = firstNonReapeting(A);
    cout<<finalAns<<endl;
    return 0;
}