#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    int vis[n] = {0};

    vis[0] = 1;

    queue<int> q;

    q.push(0);

    vector<int> bfs;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n);

    cout << "Enter the edges:" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // Since this is an undirected graph, you need to add both u and v to each other's adjacency lists
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> bfs_result = bfsTraversal(n, adj);

    cout << "BFS Traversal:\n";
    for (int node : bfs_result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
