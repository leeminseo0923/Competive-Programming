#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[20202];

int dist[20202];

void dijkstra(int start)
{
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int curDist = pq.top().first;
        int curIdx = pq.top().second;
        pq.pop();

        for (auto next : graph[curIdx])
        {
            int vertex = next.first;
            int cost = next.second;

            if (dist[vertex] == -1 || dist[vertex] > dist[curIdx] + cost)
            {
                dist[vertex] = dist[curIdx] + cost;
                pq.push(make_pair(dist[vertex], vertex));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    int k;
    cin >> k;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(make_pair(v, w));
    }

    for (int i = 1; i <= V; i++)
    {
        dist[i] = -1;
    }

    dijkstra(k);

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] < 0)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }

    return 0;
}