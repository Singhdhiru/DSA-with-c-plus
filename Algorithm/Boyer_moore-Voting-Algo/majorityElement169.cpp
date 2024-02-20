// C++ implementation for the above approach
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    ?Why Use this AlgoRithm      : https://www.codingninjas.com/studio/library/moore-s-voting-algorithm
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Q6L5SoS-fTo
    Company Tags                : Amazon, Google
    Leetcode Qn Link            : https://leetcode.com/problems/majority-element/description/
*/

// ? Using Hash map Approach 1
// ? TC    : O(n);
// ? SC    : O(n);
int findMajority_HashMap(int arr[], int n)
{
	unordered_map<int, int>mp;
    // Count occurrences of each element in the array
    for (int it = 0; it < n; it++) {
        mp[arr[it]]++;
    }

    // Find the element with the majority count
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second > n / 2) {
            return it->first; // Return the majority element
        }
    }

    return -1; // No majority element found

}
// ? Approach 2 : Moore Votting Algo
// ? TC         : O(N);
// ? SC         : O(1)
int findMajority(int arr[], int n)
{
	int candidate = -1, votes = 0;
	// Finding majority candidate
	for (int i = 0; i < n; i++) {
		if (votes == 0) {
			candidate = arr[i];
			votes = 1;
		}
		else {
			if (arr[i] == candidate)
				votes++;
			else
				votes--;
		}
	}
    // ? jo cnadidate mila use check kro uska freq sach mai n/2 se jayada hi ki nahi
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == candidate)
			count++;
	}

	if (count > n / 2)
		return candidate;
	return -1;
}
int main()
{
	int arr[] = { 1, 1, 1, 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int majority = findMajority_HashMap(arr, n);
	cout << " The majority element is : " << majority;
	return 0;
}
