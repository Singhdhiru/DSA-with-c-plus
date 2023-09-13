// There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
// Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int V, vector<pair<int, int>> &prerequisites)
    {
        // create adj list
        vector<int> adj[V];
        for (auto it : prerequisites)
        {
            // it.second hone se pale it.first task hona chahiye
            adj[it.first].push_back(it.second);
        }

        int indegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // node is in your topo sort
            // so please remove it from the indegree

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        if (topo.size() == V)
            return true;
        return false;
    }
};

int main()
{

    vector<pair<int, int>> prerequisites;
    int N = 4;
    prerequisites.push_back({1, 0});
    prerequisites.push_back({2, 1});
    prerequisites.push_back({3, 2});

    Solution obj;
    bool ans = obj.isPossible(N, prerequisites);

    if (ans)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;

    return 0;
}