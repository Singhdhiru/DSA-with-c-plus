// #include <iostream>
// using namespace std;

// int main()
// {
//     int n, m;
//     cout << "Enter the number of nodes: ";
//     cin >> n;
//     cout << "Enter the number of edges: ";
//     cin >> m;

//     int adj[n + 1][n + 1] = {0}; // Corrected size for adjacency matrix

//     cout << "Enter the edges:" << endl;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
// ?        adj[u][v] = 1; directed graph
//     }

//     cout << "Adjacency Matrix:" << endl;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cout << adj[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    int adj[n + 1][n + 1] = {0}; // Corrected size for adjacency matrix

    cout << "Enter the edges:" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;  //? undirected graph
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


