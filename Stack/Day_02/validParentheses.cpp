#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool validParentheses(string exp)
{
    int n = exp.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {

        //?if opening bracket, stack push
        //?if close bracket, stacktop check and pop
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
                //* for closing bracket
                if (!st.empty())
                {
                    char top = st.top();
                    if ((ch == ')' && top == '(') ||
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '['))
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else{
                    return false;
                }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    string exp = "[(){}](){}{[]}";
    cout << "expression is valid ->> " << validParentheses(exp) << endl;
    return 0;
}