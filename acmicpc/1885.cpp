#include <iostream>
#include <vector>
#define INF 5000000

using namespace std;

bool bellman(vector<pair<pair<int, int>, int>> edges, int start, int n)
{
    vector<int> dist(INF, n + 1);
    dist[start] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (pair<pair<int, int>, int> edge : edges)
        {
            pair<int, int> coord = edge.first;
            int cost = edge.second;

            if (dist[coord.first] != INF && dist[coord.second] > dist[coord.first] + cost)
            {
                dist[coord.second] = dist[coord.first] + cost;
                if (i == n)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, w;
        cin >> n >> m >> w;

        vector<pair<pair<int, int>, int>> edges;

        for (int i = 0; i < m; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({{s, e}, t});
            edges.push_back({{e, s}, t});
        }

        for (int i = 0; i < w; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({{s, e}, -t});
        }

        if (bellman(edges, 1, n))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}