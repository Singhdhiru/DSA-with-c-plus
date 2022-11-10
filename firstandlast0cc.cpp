// find the first and last occurence of element in array
// You have been given a sorted array/list ARR consisting of
//‘N’ elements. You are also given an integer ‘K’
#include <iostream>
using namespace std;
int FirstOcc(int arr[], int n, int key) {
  int s = 0;
  int e = n - 1;
  int ans = -1;
  int mid = s + (e - s) / 2;
  while (s <= e) {

    if (arr[mid] == key) {
      ans = mid;
      e = mid - 1;
    } else if (key > arr[mid]) { // Right me jao
      s = mid + 1;
    } else if (key < arr[mid]) { // left me jao
      e = mid - 1;
    }

    mid = s + (e - s) / 2;
  }
  return ans;
  }
  int LastOcc(int arr[], int n, int key) {
    int s = 0;
    int e = n - 1;
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e) {

      if (arr[mid] == key) {
        ans = mid;
        s = mid + 1;
      } else if (key > arr[mid]) { // Right me jao
        s = mid + 1;
      } else if (key < arr[mid]) { // left me jao
        e = mid - 1;
      }

      mid = s + (e - s) / 2;
    }
    return ans;
  }

  int main() {
    int even[6] = {1, 2, 3, 3, 4, 5}; // array present in sorted order
    cout << "left occurrence of element present at index"
         << FirstOcc(even, 6, 3) << endl;
    cout << "right occurrence of element present at index"
         << LastOcc(even, 6, 3) << endl;
  }