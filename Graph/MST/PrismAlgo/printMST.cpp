#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    // create adjacency list
    unordered_map<int, vector<pair<int, int>> > adj;
    for (auto i : g) {
        int u = i.first.first;
        int v = i.first.second;
        int w = i.second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // min heap to get the node with the minimum weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    // let source as 1, and initially the distance of the source is 0
    // {weight, node}
    pq.push({0, 1});

    vector<int> key(n + 1, INT_MAX), parent(n + 1, -1), visited(n + 1, 0);

    parent[1] = -1;
    // weight to reach i is key[i]
    key[1] = 0;

    while (pq.size()) {
        int w = pq.top().first;
        int node = pq.top().second;
        visited[node] = 1;
        pq.pop();

        // find the node with minimum weight and go to its neighbor
        for (auto neg : adj[node]) {
            int toGo = neg.first;
            int toGoWeg = neg.second;

            // if to reach node N from key[N] update the weight (key[N]) with the distance from the node to N
            if (visited[toGo] == 0 && toGoWeg < key[toGo]) {
                key[toGo] = toGoWeg;
                parent[toGo] = node;
                pq.push({toGoWeg, toGo});
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    // loop from 2 because the parent of 1 is -1 (1 is the initial node)
    for (int i = 2; i <= n; i++) {
        ans.push_back({{parent[i], i}, key[i]});
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, edges);

    // Print the Minimum Spanning Tree edges and their weights
    for (auto edge : mst) {
        int u = edge.first.first;
        int v = edge.first.second;
        int weight = edge.second;
        cout << "Edge: " << u << " - " << v << " Weight: " << weight << endl;
    }

    return 0;
}
