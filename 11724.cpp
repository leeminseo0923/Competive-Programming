#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int> graph[], int start, bool visited[])
{
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        start = q.front();
        q.pop();
        for (int i = 0; i < graph[start].size(); i++)
        {
            if (!visited[graph[start][i]])
            {
                q.push(graph[start][i]);
                visited[graph[start][i]] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> graph[n];
    bool visited[n];
    fill_n(visited, n, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[v - 1].push_back(u - 1);
        graph[u - 1].push_back(v - 1);
    }
    int ctn = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(graph, i, visited);
            ctn++;
        }
    }
    cout << ctn;
    return 0;
}