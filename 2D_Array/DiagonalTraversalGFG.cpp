#include <iostream>
#include <vector>
using namespace std;
// * https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1
vector<int> matrixDiagonally(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<int> ans;
    int i = 0;
    int j = 0;
    int upper = 1; // yani dirction of diagonals
    //  1 : bottom to up
    // 0  : upper to bottom
    while (ans.size() < n * n)
    {
        // bottom to upper
        if (upper == 1)
        {
            while (i >= 0 && j < n)
            {
                ans.push_back(mat[i][j]);
                // upper to jaunga per break point bhi hona chahiye
                if (j == n - 1)
                {
                    i++;
                    break;
                }
                else if (i == 0)
                {
                    j++; // jaha i == 0 hoga phir j++ kar dunga yani next col mai cahla
                         // jaunga aur waha se phir downwords direction mai jaunga
                    break;
                }
                i--; // Upper jane per i decarse hoga
                j++; // upper jane per j increaese karega
            }
            upper = 0;
        }
        // upper to bottom
        else
        {
            // down jab tak jaunga i < n hoo and j jab tak zero n ho jaye
            while (i < n && j >= 0)
            {
                ans.push_back(mat[i][j]);
                if (i == n - 1)
                {
                    j++;
                    break;
                }
                else if (j == 0)
                {
                    i++;
                    break;
                }
                i++;
                j--;
            }
            upper = 1;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = matrixDiagonally(vec);
    for (auto &it : ans)
    {
        cout << it << " ";
    }

    return 0;
}
