#include <iostream>
#include <vector>
using namespace std;

// ? Question link->> https://www.geeksforgeeks.org/problems/koko-eating-bananas/1
int Solve(int n, vector<int> &piles, int h)
{
    int start = 0;
    int end = 0;
    long long sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += piles[i];
        // piles[i] yani maximum itna kha sakta hi
        end = max(end, piles[i]);
    }
    // itna to banaan khana hi padega minimum
    start = sum / h;
    if (start == 0)
    {
        start = 1;
    }

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int total_time = 0;
        for (int i = 0; i < n; i++)
        {
            total_time += piles[i] / mid;
            // agar fraction aayega toh use handle kr lunga
            if (piles[i] % mid)
            {
                total_time++;
            }
        }
        if (total_time > h)
        {
            // aur tezi se banana khilaoo
            start = mid + 1;
        }
        else
        {
            // ans store kr ke speed slow kr dunag
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    // Example usage
    int n = 5;
    vector<int> piles = {30, 11, 23, 4, 20};
    int h = 6;

    int result = Solve(n, piles, h);

    cout << "Minimum speed required: " << result << endl;

    return 0;
}
