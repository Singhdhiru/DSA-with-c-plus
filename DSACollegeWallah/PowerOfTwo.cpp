// leet code
// power of two-> 
#include <iostream>
using namespace std;
bool isPowerOfTwo(int n)
{
    return (n>0) && !((n) & (n-1));
}
int main()
{
    int n;
    cout << "Enter the number->";
    cin >> n;
    bool ans = isPowerOfTwo(n);
    cout << "ans->" << ans << endl;
    return 0;
}