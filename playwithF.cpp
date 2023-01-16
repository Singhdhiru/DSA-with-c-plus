// paly with function
#include <iostream>
using namespace std;
int sum(int a, int b)
{
  cout << "enter two number a and b" << endl;
  cin >> a >> b;
  int sum = 0;
  sum = sum + a + b;
  return sum;
}
int main()
{
  int a, b;
  cout << sum(a, b) << endl;
  cout << sum(a, b) << endl;
}