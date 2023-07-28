// Given an array Arr of size N, the array contains numbers in range from 0 to K-1 where K is a positive integer and K <= N. Find the maximum repeating number in this array. If there are two or more maximum repeating numbers return the element having least value.


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> mp;

    int maxfreq = 0;
    int maxans = 0;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        maxfreq = max(maxfreq, mp[arr[i]]);
    }

    for (int i = 0; i < n; i++)
    {
        if (maxfreq == mp[arr[i]])
        {
            maxans = arr[i];
            break;
        }
    }

    return maxans;
}

int main()
{
    // Test the maximumFrequency function with a sample vector
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int n = arr.size();

    int result = maximumFrequency(arr, n);

    cout << "Element with maximum frequency: " << result << endl;

    return 0;
}

