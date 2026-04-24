#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

vector<Edge> edges;
int parent[100];

int findParent(int node)
{
    if(parent[node] == node)
        return node;

    return findParent(parent[node]);
}

void unionSet(int u, int v)
{
    int pu = findParent(u);
    int pv = findParent(v);

    parent[pu] = pv;
}

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    int n, e;
    cin >> n >> e;

    for(int i=0;i<e;i++)
    {
        Edge temp;
        cin >> temp.u >> temp.v >> temp.w;
        edges.push_back(temp);
    }

    sort(edges.begin(), edges.end(), cmp);

    for(int i=0;i<n;i++)
        parent[i] = i;

    int cost = 0;

    for(int i=0;i<edges.size();i++)
    {
        Edge edge = edges[i];

        if(findParent(edge.u) != findParent(edge.v))
        {
            cout << edge.u << " - " << edge.v << " = " << edge.w << endl;
            cost += edge.w;
            unionSet(edge.u, edge.v);
        }
    }

    cout << "Total Cost = " << cost;

    return 0;
}