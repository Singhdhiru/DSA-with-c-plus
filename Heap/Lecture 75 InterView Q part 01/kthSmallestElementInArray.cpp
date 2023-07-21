#include <iostream>
#include <queue>
using namespace std;
// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq;
    // step->> 01 make first k element to max heap
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // step->>> 02 rest n-k element compare root
    for (int i = k; i <= r; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}
int main()
{
    int size = 5;
    int arr[5] = {4, 1, 3, 9, 7};
    int k = 3;
    int kthSmall = kthSmallest(arr, 0, 5, k);
    cout<<"kth smallest element in the array: "<<kthSmall<<endl;
    return 0;
}
