#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;

int busCost[101][101];
int n;

void dijkstra(int start)
{
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);

    dist[start] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        int next = -1;
        int minimum = INF;
        for (int j = 1; j < n + 1; j++)
        {
            if (dist[j] < minimum && !visited[j])
            {
                next = j;
                minimum = dist[j];
            }
        }
        if (next == -1)
            break;
        visited[next] = true;

        for (int j = 1; j < n + 1; j++)
        {
            if (busCost[next][j] == 0)
                busCost[next][j] = INF;
            dist[j] = min(dist[j], busCost[next][j] + minimum);
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (dist[i] == INF)
        {
            cout << 0;
        }
        else
        {
            cout << dist[i];
        }
        if (i < n)
        {
            cout << ' ';
        }
    }
}

int dist[101][101];

void floyd()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (i == j)
                    dist[i][j] = 0;
                else if (busCost[i][j])
                    dist[i][j] = busCost[i][j];
                else
                    dist[i][j] = INF;
            }
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    cin >> n;
    int m;
    cin >> m;

    for (int k = 0; k < m; k++)
    {
        int i, j, c;
        cin >> i >> j >> c;

        if (busCost[i][j] > 0)
            busCost[i][j] = min(busCost[i][j], c);
        else
            busCost[i][j] = c;
    }

    floyd();

    // for (int i = 1; i < n + 1; i++)
    // {
    //     dijkstra(i);
    //     cout << '\n';
    // }

    return 0;
}