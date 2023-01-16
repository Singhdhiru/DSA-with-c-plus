//  in this code we see how to find intersection of two array
#include <iostream>
#include <vector>
using namespace std;
vector<int> findArrayIntersection(vector<int> &v1, int n, vector<int> &v2, int m)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (v1.at(i) == v2.at(j))
        {
            ans.push_back(v1.at(i));
            i++;
            j++;
        }
        else if (v1.at(i) > v2.at(j))
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return ans;
}
int main()
{
    vector<int> v1;
    v1.push_back(6);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);
    cout << "print the vector1->";
    for (int i : v1)
    {
        cout << i << " ";
    }
    cout << endl;
    int n = v1.size();
    cout << "print the size of vector v1->" << n << endl;
    vector<int> v2;
    v2.push_back(6);
    v2.push_back(9);
    v2.push_back(7);
    v2.push_back(11);
    v2.push_back(13);
    v2.push_back(9);
    cout << "print the vector2->";
    for (int i : v2)
    {
        cout << i << " ";
    }
    cout << endl;
    int m = v2.size();
    cout << "size of vector v2 ->" << m << endl;
    vector<int> ArrayInter = findArrayIntersection(v1, n, v2, m);
    cout << "print the intersection of v1 & v2->";
    for (int i : ArrayInter)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}