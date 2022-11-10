// first we think why use binary search and why not use linaer serch
// time complexity of linear search = o(n) in worst case
// whe n is equal to number of array present in array
// time compexity of binary search = o(logn)
#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int key) {
  int start = 0;
  int end = n - 1;
  int mid = start + end / 2; // better way to find mid = start+(end-start/2);
  while (start <= end) {  // terminating condition
    if (arr[mid] == key) {
      return mid;
    }
    if (arr[mid] > key) {
      end = mid - 1;
    }
    if (arr[mid] < key) {
      start = mid + 1;
    }
    mid = start + end / 2;
  }
  return -1;
}
int main() {
  int evenarr[6] = {23, 35, 47, 67,78, 89}; // always array in incresing ans decresing order
  int oddarr[5] = {11, 23, 45, 47, 58};
  int oddindex = binarySearch(oddarr, 5, 450);
  cout << "element present in index" << " " << oddindex << " " << endl;
  int evenindex = binarySearch(evenarr, 6, 899);
  cout << "element present in index"<< " " << evenindex << endl;
}