// #include <iostream>
// #include <unordered_map>
// #include <list>
// #include <vector>

// using namespace std;

// void dfs(int node, unordered_map<int, bool> &visited,
//         unordered_map<int, list<int>> &adj, vector<int> &component)
// {

//     component.push_back(node);
//     visited[node] = true;

//     for (auto i : adj[node])
//     {
//         if (!visited[i])
//         {
//             dfs(i, visited, adj, component);
//         }
//     }
// }

// vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
// {
//     unordered_map<int, list<int>> adj;
//     for (int i = 0; i < edges.size(); i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         adj[v].push_back(u);
//         adj[u].push_back(v);
//     }
//     vector<vector<int>> ans;
//     unordered_map<int, bool> visited;
//     for (int i = 0; i < V; i++)
//     {
//         if (!visited[i])
//         {
//             vector<int> component;
//             dfs(i, visited, adj, component);
//             ans.push_back(component);
//         }
//     }
//     return ans;
// }

// int main()
// {
//     int V = 6; // Number of vertices
//     int E = 5; // Number of edges
//     vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {4, 5}};

//     vector<vector<int>> components = depthFirstSearch(V, E, edges);

//     for (const auto &component : components)
//     {
//         cout << "Component: ";
//         for (int node : component)
//         {
//             cout << node << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], int visited[], vector<int>& ans) {
    visited[node] = 1;
    ans.push_back(node);
    for (auto nbr : adj[node]) {
        if (!visited[nbr]) {
            dfs(nbr, adj, visited, ans);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    int visited[V] = {0};
    int startNode = 0;
    vector<int> ans;
    dfs(startNode, adj, visited, ans);
    return ans;
}

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<int> adj[V];
    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming an undirected graph
    }

    vector<int> traversal = dfsOfGraph(V, adj);

    cout << "DFS Traversal of the graph:" << endl;
    for (int node : traversal) {
        cout << node << " ";
    }

    return 0;
}

