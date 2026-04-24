#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure for node in priority queue
struct Node
{
    int vertex;
    int g;   // cost from start node
    int h;   // heuristic value
    int f;   // g + h

    bool operator<(const Node &other) const
    {
        return f > other.f;   // min priority queue
    }
};

// Adjacency list: {neighbor, cost}
vector<pair<int,int>> graph[100];

int heuristic[100];
bool visited[100];

// A* Algorithm
void aStar(int start, int goal)
{
    priority_queue<Node> pq;

    pq.push({start, 0, heuristic[start], heuristic[start]});

    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();

        int u = current.vertex;

        if (visited[u])
            continue;

        visited[u] = true;

        cout << u << " ";

        if (u == goal)
        {
            cout << "\nGoal Reached";
            return;
        }

        for (auto it : graph[u])
        {
            int v = it.first;
            int cost = it.second;

            if (!visited[v])
            {
                int gNew = current.g + cost;
                int hNew = heuristic[v];
                int fNew = gNew + hNew;

                pq.push({v, gNew, hNew, fNew});
            }
        }
    }
}

int main()
{
    int n, e;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    // Input graph edges
    for (int i = 0; i < e; i++)
    {
        int u, v, w;

        cout << "Enter node1 node2 weight: ";
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});   // undirected graph
    }

    // Input heuristic values
    cout << "Enter heuristic values:\n";
    for (int i = 0; i < n; i++)
        cin >> heuristic[i];

    int start, goal;

    cout << "Enter start node: ";
    cin >> start;

    cout << "Enter goal node: ";
    cin >> goal;

    cout << "\nPath Traversed: ";

    aStar(start, goal);

    return 0;
}