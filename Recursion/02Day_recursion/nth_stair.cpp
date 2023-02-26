#include <iostream>
using namespace std;

int countDistinctWays(int nStairs)
{
    if (nStairs < 0)
    {
        return 0;
    }
    //* only one way to reach the first stair
    // * as you are already standing on its
    if (nStairs == 0)
    {
        return 1;
    }
    return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
}
int main()
{
    int stair;
    cout << "enter the nth stair->>";
    cin >> stair;
    int ans = countDistinctWays(stair);
    cout<<ans<<endl;
    return 0;
}