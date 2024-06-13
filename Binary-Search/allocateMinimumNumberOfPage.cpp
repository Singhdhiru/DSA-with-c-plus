#include <bits/stdc++.h>
using namespace std;
/*
Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countStudents() function for the value of ‘mid’. Now, inside the countStudents() function, we are using a loop that runs for N times.

Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/
// * Question ->> https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
int countStudent(vector<int>A, int page, int n)
{
    int studentCnt = 1;      // student ko 1 maan liya
    long long pageCount = 0; // intial count 0 maan liya
    // int n = sizeof(A)/sizeof(A[0]);
    for (int i = 0; i < n; i++)
    {
        if (pageCount + A[i] <= page)
        {
            pageCount += A[i];
        }
        // next student per move kr jaunga allocate karne ke liye
        else
        {
            studentCnt++;
            // naye student ke liye pageCount ko intilize kar dunga
            pageCount = A[i];
        }
    }
    return studentCnt;
}
// Function to find minimum number of pages.
int findPages(vector<int>A, int N, int M)
{
    if (N < M)
    {
        return -1; // Not enough books for each student to have at least one
    }
    int high = 0;
    int low = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        high += A[i];
        low = max(low, A[i]);
    }

    while (low <= high)
    {
        int mid = (high + low) / 2;
        // check karunga mid itna page sabhi mai distribute kr sakta hu ya nahi
        int student = countStudent(A, mid, N);
        if (student > M)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
