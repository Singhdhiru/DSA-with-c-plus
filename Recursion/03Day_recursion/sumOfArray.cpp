//* sum of arrray using recursion
#include <iostream>
using namespace std;

int getSum(int arr[], int size)
{

    // *base case
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }

    int remainingPart = getSum(arr + 1, size - 1);
    int sum = arr[0] + remainingPart;
    return sum;
}
int main()
{
    int arr[6] = {2, 9, 10, 12, 14, 45};
    int size = 6;

    int sum = getSum(arr, size);
    cout << "sum of array using recursion->" << sum << endl;
    return 0;
}