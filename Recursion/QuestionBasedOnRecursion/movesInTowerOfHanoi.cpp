#include <iostream>

using namespace std;

long long toh(int N, int from, int to, int aux)
{
    if (N == 1)
    {
        cout << "move disk 1 from rod " << from << " to rod " << to << endl;
        return 1;
    }

    long long count = 0;

    long long c1 = toh(N - 1, from, aux, to);

    cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;

    long long c2 = toh(N - 1, aux, to, from);

    return c1 + c2 + 1;
}

int main()
{
    int N, from, to, aux;

    // Get input for the towers of hanoi
    cout << "Enter the number of disks: ";
    cin >> N;

    // Assuming three rods (1, 2, 3)
    from = 1;
    to = 3;
    aux = 2;

    long long totalMoves = toh(N, from, to, aux);

    cout << "Total number of moves: " << totalMoves << endl;

    return 0;
}
