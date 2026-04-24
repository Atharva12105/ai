#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100];
bool visited[100];
queue<int> q;

// Recursive DFS
void dfs(int node)
{
    visited[node] = true;
    cout << node << " ";

    for (auto it : graph[node])
    {
        if (!visited[it])
        {
            dfs(it);
        }
    }
}

// Recursive BFS
void bfs()
{
    if (q.empty())
        return;

    int node = q.front();
    q.pop();

    cout << node << " ";

    for (auto it : graph[node])
    {
        if (!visited[it])
        {
            visited[it] = true;
            q.push(it);
        }
    }

    bfs();
}

int main()
{
    int n, e;
    cin >> n >> e;

    int u, v;

    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u); // undirected graph
    }

    cout << "DFS Traversal: ";
    dfs(0);

    // Reset visited array for BFS
    for (int i = 0; i < 100; i++)
        visited[i] = false;

    cout << "\nBFS Traversal: ";

    visited[0] = true;
    q.push(0);

    bfs();

    return 0;
}