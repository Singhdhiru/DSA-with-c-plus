#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, int vis[], int v) {
    vis[node] = true;
    for (int i = 0; i < v; i++) {
        if (adj[node][i] == 1 && vis[i] == 0) {
            dfs(i, adj, vis, v);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V) {
    int visted[V] = {0};
    int cnt = 0;
    for (int i = 0; i < V; i++) {
        if (visted[i] == 0) {
            cnt++;
            dfs(i, adj, visted, V);
        }
    }
    return cnt;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adjacencyMatrix(V, vector<int>(V, 0));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    int provinces = numProvinces(adjacencyMatrix, V);
    cout << "Number of provinces: " << provinces << endl;

    return 0;
}
