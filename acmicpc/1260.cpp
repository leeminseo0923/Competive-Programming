#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(vector<int> graph[], int start, bool visited[])
{
    visited[start] = true;
    cout << start;
    for (int i = 0; i < graph[start].size(); i++)
    {
        if (!visited[graph[start][i]])
        {
            cout << ' ';
            dfs(graph, graph[start][i], visited);
        }
    }
    return;
}

void bfs(vector<int> graph[], int start, bool visited[])
{
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        cout << n;
        for (int i = 0; i < graph[n].size(); i++)
        {
            if (!visited[graph[n][i]])
            {
                q.push(graph[n][i]);
                visited[graph[n][i]] = true;
            }
        }
        if (!q.empty())
        {
            cout << ' ';
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, v;
    cin >> n >> m >> v;
    vector<int> graph[n + 1];
    bool visited[n + 1];
    fill_n(visited, n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n + 1; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(graph, v, visited);
    cout << '\n';
    fill_n(visited, n + 1, false);
    bfs(graph, v, visited);

    return 0;
}