#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure for Edge
struct Edge
{
    int u, v, w;
};

// Store all edges
vector<Edge> edges;

// Parent array for Disjoint Set
int parent[100];

// Find ultimate parent
int findParent(int node)
{
    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent[node]);
}

// Union two sets
void unionSet(int u, int v)
{
    int pu = findParent(u);
    int pv = findParent(v);

    parent[pu] = pv;
}

int main()
{
    int n, e;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    // Input edges
    for (int i = 0; i < e; i++)
    {
        Edge temp;

        cout << "Enter node1 node2 weight: ";
        cin >> temp.u >> temp.v >> temp.w;

        edges.push_back(temp);
    }

    // Sort edges according to weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
    {
        return a.w < b.w;
    });

    // Initialize parent array
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int cost = 0;

    cout << "\nEdges in MST:\n";

    // Kruskal Algorithm
    for (auto edge : edges)
    {
        if (findParent(edge.u) != findParent(edge.v))
        {
            cout << edge.u << " - " << edge.v << " = " << edge.w << endl;

            cost += edge.w;

            unionSet(edge.u, edge.v);
        }
    }

    cout << "Total Cost = " << cost;

    return 0;
}