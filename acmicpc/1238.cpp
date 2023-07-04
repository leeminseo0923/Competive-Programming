#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000

using namespace std;

int fromCost[1001][1001];
int toCost[1001][1001];
int n;

vector<int> dijkstra(int start, int cost[1001][1001])
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
            if (cost[next][j] == 0)
                cost[next][j] = INF;
            dist[j] = min(dist[j], cost[next][j] + minimum);
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, x;
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cin >> fromCost[a][b];
        toCost[b][a] = fromCost[a][b];
    }

    vector<int> fromStart = dijkstra(x, fromCost);
    vector<int> toStart = dijkstra(x, toCost);

    vector<int> sum;
    for (int i = 1; i <= n; i++)
    {
        sum.push_back(fromStart[i] + toStart[i]);
    }

    cout << *max_element(sum.begin(), sum.end());

    return 0;
}