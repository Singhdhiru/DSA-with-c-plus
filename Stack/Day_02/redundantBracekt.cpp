// ? Q. Redundant Brackets->> agar faltu ka bracket ho toh use true return kr denge
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// bool checkRedundant(string &str){
//     stack<char> st;
//     for(int i=0; i<str.size(); i++){
//         char ch = str[i];
//         if(ch == '(' || ch == '*' || ch == '/' || ch == '+' || ch == '-'){
//             st.push(ch);
//         }
//         else{
//             //?ch ya toh ')' hai or lowercase letter

//             if(ch == ')'){
//                 bool isRedundant = true;
//                 // * ab check karenge ki opening barcket
//                 while(st.top() != '('){
//                     char top = st.top();
//                     if(top == '(' || top == '*' || top == '/' || top == '+' || top == '-'){
//                         isRedundant = false;
//                     }
//                     st.pop();
//                 }

//                 if(isRedundant == true){
//                     return true;
//                 }
//                 st.pop();
//             }
//         }
//     }
//     return false;
// }
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    bool isRedundant = false;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            //?ch ya toh ')' hai or lowercase letter

            if (ch == ')')
            {
                isRedundant = true;

                while (!st.empty() && st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant == true)
                    return true;
                st.pop();
            }
        }
    }
    if (st.empty() && isRedundant == false)
        return false;
    else
        return true;
}
int main()
{
    string str = "((a/b))";
    cout << "this expression is valid or not ->> " << findRedundantBrackets(str) << endl;
    string str1 = "(a+b)";
    cout << "this expression is valid or not ->> " << findRedundantBrackets(str1) << endl;
    return 0;
}