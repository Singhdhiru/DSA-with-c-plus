#include <iostream> // Include the necessary header file for input/output
#include <queue>    // Include the header file for priority_queue

using namespace std;

//Function to return the minimum cost of connecting the ropes.
long long minCost(long long arr[], long long n) {
    // create min heap
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (long long i = 0; i < n; i++) {
        pq.push(arr[i]);
    }
    long long cost = 0;
    while (pq.size() > 1) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        long long sum = a + b;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}

int main() {
    // Example usage
    long long arr[] = {4, 3, 2, 6};
    long long n = sizeof(arr) / sizeof(arr[0]);

    long long result = minCost(arr, n);
    cout << "Minimum cost of connecting the ropes: " << result << endl;

    return 0;
}
