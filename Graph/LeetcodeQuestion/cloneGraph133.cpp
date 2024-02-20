/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=z7mPg_xT5xk
    Company Tags                : Google, Facebook, Amazon
    Leetcode Qn Link            : https://leetcode.com/problems/clone-graph/
*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
unordered_map<Node *, Node *> mp;
void dfs(Node *node, Node *clone_node)
{
    // node_neighbor -> orianal node(node) ke neighbor mai traverse kr ke clone node ke niegh mai add kar denge 
    for (Node *node_neighbor : node->neighbors)
    {
        // iska matlba hi node->neighbor mai node_nieghbor nahi hi
        if (mp.find(node_neighbor) == mp.end())
        {
            // clone node ke nieghbor mai orignak node ke neighbor ko copy kar denge
            Node *clone_node_neighbors = new Node(node_neighbor->val);
            mp[node_neighbor] = clone_node_neighbors;
            clone_node->neighbors.push_back(clone_node_neighbors);
            dfs(node_neighbor, clone_node_neighbors);
        }
        else
        {
            // agar wo mp mai mark hi iska matlab uska clone ho chuka only nieghbor mai add kr do
            clone_node->neighbors.push_back(mp[node_neighbor]);
        }
    }
}
Node *cloneGraph(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    mp.clear();
    Node *clone_node = new Node(node->val);
    mp[node] = clone_node;
    // ? first Node aur uska clone_node bna diya aur se dfs mai send kr siya
    dfs(node, clone_node);
    return clone_node;
}

int main()
{
    // Create nodes for testing
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    // Build connections between nodes
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    // Clone the graph
    Node *clonedGraph = cloneGraph(node1);

    // Print the original and cloned graph for verification
    cout << "Original Graph:" << endl;
    // printGraph(node1);

    cout << "\nCloned Graph:" << endl;
    // printGraph(clonedGraph);

    return 0;
}
