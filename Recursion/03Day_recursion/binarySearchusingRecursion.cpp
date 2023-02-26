//* implementation of binary search  using recursion
#include <iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int key)
{
    if (s > e){
        return false;
    }
    int mid = s+(e-s)/2;

    if(arr[mid] == key){
        return true;
    }
    if(arr[mid]<key){
        //* right mai jaoo bhai
        binarySearch(arr, mid+1, e, key);
    }
    else{
        //* left mai jaoo bhai
        binarySearch(arr, s, mid-1, key);
    }
}

int main()
{
    int arr[6] = {2, 9, 10, 12, 14, 45};
    int size = 6;
    int key = 450;
    bool ans = binarySearch(arr, 0, 6, 450);
    if (ans)
    {
        cout << "element is present" << endl;
    }
    else
    {
        cout << "element is not present" << endl;
    }
    return 0;
}