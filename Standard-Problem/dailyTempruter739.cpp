#include <bits/stdc++.h>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ZhZEmGv-sOY
    Company Tags                : Google, Meta, Tokopedia
    Leetcode Link               : https://leetcode.com/problems/daily-temperatures/
*/
// T.C : O(n)
// S.C : O(n)
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    stack<int> st;

    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--)
    {
        // ?temperatures[st.top()->> idx oof top elemment hi]
        while (!st.empty() && temperatures[i] >= temperatures[st.top()]) 
        {
            st.pop();
        }

        if (st.empty())
        {
            result[i] = 0;
        }
        else
        {
            result[i] = st.top() - i; // days
        }
        // indx push kar rahe hi isme na ka element
        st.push(i);
    }

    return result;
}
int main() {
    // Example usage:
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    
    vector<int> result = dailyTemperatures(temperatures);
    
    cout << "Resulting days: ";
    for (int days : result) {
        cout << days << " ";
    }
    
    return 0;
}