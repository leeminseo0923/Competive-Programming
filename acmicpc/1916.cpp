#include <bits/stdc++.h>

#define INF 2000000002

using namespace std;

int graph[1001][1001];
int dist[1001];

void dijkstra(int start, int n)
{
    dist[start] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, start));

    while (!q.empty())
    {
        int cost = q.top().first;
        int cur = q.top().second;

        q.pop();

        if (dist[cur] < cost)
            continue;
        for (int i = 1; i < n + 1; i++)
        {
            if (graph[cur][i] >= 0)
            {
                if (graph[cur][i] + cost < dist[i])
                {
                    dist[i] = graph[cur][i] + cost;
                    q.push(make_pair(dist[i], i));
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = INF;
            if (i == j)
            {
                graph[i][j] = 0;
            }
        }
    }

    while (m--)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        if (cost < graph[start][end])
            graph[start][end] = cost;
    }

    int startCity, endCity;
    cin >> startCity >> endCity;

    for (int i = 1; i < n + 1; i++)
    {
        dist[i] = INF;
    }

    dijkstra(startCity, n);

    cout << dist[endCity];

    return 0;
}