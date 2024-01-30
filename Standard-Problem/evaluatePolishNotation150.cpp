#include <iostream>
#include <vector>
#include <stack>
#include <functional>
#include<unordered_map>
#include <string>
using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=BM-bu4tJz7U
    Company Tags                : Apple, Microsoft, Flipkart, Amazon, LinkedIn
    Leetcode Link               : https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/

/********************************************************************* C++ ************************************************************************/
//Approach-1 (Basic stack approach)
//T.C : O(n)
//S.C : O(n)

/*
ye code ->> codestudio per work karega
int modInverse(int a, int m) {
    Find modular inverse using extended Euclidean algorithm
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

int operate(int& a, int& b, const string& token) {
    if (token == "+") {
        return (a + b) % mod;
    }
    if (token == "-") {
        return (a - b + mod) % mod;
    }
    if (token == "*") {
        return (static_cast<long>(a) * b) % mod;
    }
    if (token == "/") {
        Find modular inverse of b
        int invB = modInverse(b, mod);
        return (static_cast<long>(a) * invB) % mod;
    }
    return -1;
} 
*/
int  operate(int& a, int &b, const string &token){
        if(token == "+"){
            return a+b;
        }
        if(token == "-"){
            return a-b;
        }
        if(token == "*"){
            return long(a) * long(b); //? overflow n kare isilye use kiya gaya hi long long
        }
        if(token == "/"){
            return static_cast<double>(a) / static_cast<double>(b); //? code studio per divide wala functio kaan nahi karega isliye module inverse use karna padega
        }
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int res = 0;
        for(const string& token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"  ){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                res = operate(a,b,token);
                st.push(res);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }

/*
    Using fancy Lambda on unordered_map
    For my fancy STL collection with easy exlanation with examples, see the link below -
    https://github.com/MAZHARMIK/Cpp-STL-Quick-Help/blob/main/README.md
*/
int evalRPN_using_lambdaFunction(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        
        unordered_map<string, function<int (int, int)> > mp = {
            {"+", [](int a, int b) {return a + b; } },
            {"-", [](int a, int b) {return a - b; } },
            {"*", [](int a, int b) {return (long)a * (long)b; } },
            {"/", [](int a, int b) {return a / b; } },
        };
        
        for(const string& s:tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                result = mp[s](a, b);
                st.push(result);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
int main() {
    // Example usage:
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    int result = evalRPN(tokens);
    
    cout << "Result: " << result << endl;

    return 0;
}
