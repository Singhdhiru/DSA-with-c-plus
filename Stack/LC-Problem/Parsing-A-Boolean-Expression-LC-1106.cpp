#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=AXfTSqFUopw
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/parsing-a-boolean-expression
*/

//*Approach (Using stack)
// T.C : O(n)
// S.C : O(n)
class Solution
{
public:
    char solveOp(char op, vector<char>& values) {
        if (op == '!') 
            return values[0] == 't' ? 'f' : 't';
    
        if (op == '&') 
            return any_of(values.begin(), values.end(), [](char ch) { return ch == 'f'; }) ? 'f' : 't';
    
        if (op == '|') 
            return any_of(values.begin(), values.end(), [](char ch) { return ch == 't'; }) ? 't' : 'f';
    
        return 't'; // Unreachable
    }
    bool parseBoolExpr(string s)
    {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ',')
                continue;

            if (s[i] == ')')
            {
                vector<char> values;
                // Gather all values inside the parentheses
                while (st.top() != '(')
                {
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop(); // Remove '('
                char op = st.top();
                st.pop(); // Remove the operator
                st.push(solveOp(op, values));
            }
            else
            {
                st.push(s[i]);
            }
        }
        return (st.top() == 't');
    }
};

int main()
{
    Solution solution;

    // Example input
    string expression = "|(f,t)"; // Change this to test different expressions
    bool result = solution.parseBoolExpr(expression);

    cout << "Result of expression '" << expression << "' is: " << (result ? "true" : "false") << endl;

    return 0;
}