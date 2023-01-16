// complement of number i/p = 10->1010
// o/p = 5->0101
#include <iostream>
using namespace std;
int bitwiseComplement(int n)
{
    // edge case
    if (n == 0)
    {
        return 1;
    }
    int m = n;
    int mask = 0;
    while (m != 0)
    {
        mask = (mask << 1) | (1);
        m = m >> 1;
    }
    int ans = (~n) & (mask);
    return ans;
}
int main()
{
    int n;
    cout << "enter the number ->";
    cin >> n;
    int Ans = bitwiseComplement(n);
    cout << "bitwiseComplement of number->" << Ans << endl;
    return 0;
}