// implement linear or sequential search
#include <iostream>
using namespace std;
bool Search(int arr[], int key, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int key, size;
    cout << "enter size of array->";
    cin >> size;
    cout << "enter the key value->";
    cin >> key;
    int arr[100];
    // taking input in array
    for (int i = 0; i <= size; i++)
    {
        cin >> arr[i];
    }
    bool found = Search(arr, key, size);
    if (found)
    {
        cout << "key is present->" << endl;
    }
    else
    {
        cout << "key is absent->" << endl;
    }
    return 0;
}