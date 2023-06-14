#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};
int tour(petrolPump p[], int n)
{
    int start = 0;
    int requiredFuel = 0;
    int extraFuel = 0;
    for (int i = 0; i < n; i++)
    {
        extraFuel += (p[i].petrol - p[i].distance);
        if (extraFuel < 0)
        {
            start = i + 1;
            requiredFuel += extraFuel;
            extraFuel = 0;
        }
    }
    if (requiredFuel + extraFuel >= 0)
    {
        return start;
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter the number of petrol pumps: ";
    cin >> n;

    petrolPump p[n];
    cout << "Enter the petrol and distance values for each pump:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].petrol >> p[i].distance;
    }

    int start = tour(p, n);
    if (start == -1)
    {
        cout << "No possible solution.\n";
    }
    else
    {
        cout << "Start at petrol pump " << start << ".\n";
    }

    return 0;
}
