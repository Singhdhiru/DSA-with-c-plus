#include <bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>> &m, int a, int b, int n)
{
    if(m[a][b] == 1){
        return true;
    }
    else{
        return false;
    }
}
int celebrity(vector<vector<int>> &m, int n)
{
    stack<int> s;
    // ? step ->>1: push all element inn the stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // ? step -> 01 : get two element and compare them
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (knows(m, a, b, n))
        {
            s.push(b);
        }
        else{
            s.push(a);
        }
    }

    int ans = s.top();

    // ? step -> 03 : single element in the stack is potensial celeb
    // ? varify them

    // ? row check
    int zeroCount = 0;
    for(int i=0; i<n; i++){
        if (m[ans][i] == 0){
            zeroCount++;
        }
    }

    // ? all zeroes
    if(zeroCount != n){
        return -1;
    }

    // ? columnn check
    int oneCount = 0;
    for(int i=0; i<n; i++){
        if(m[i][ans] == 1){
            oneCount++;
        }
    }

    if(oneCount != n-1){ //* dignoal element ko chhod kr cheeck kr lenge
        return -1;
    }

    return ans;
}
int main()
{
    int n = 3;
    vector<vector<int>> m = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    int theCelebrity = celebrity(m, n);
    cout << "celebrity is ->> " << theCelebrity << endl;
    return 0;
}