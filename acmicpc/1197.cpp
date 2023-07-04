#include <iostream>
#include <queue>
#include <vector>
#define INF 2000000;

using namespace std;

vector<pair<int, int>> adj[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> weight;
bool visited[10001];

int prim(int v)
{
    int result = 0;
    weight.push({0, 1});
    for (int i = 0; i < v; i++)
    {
        int cur = 0, minWeight = INF;
        while (!weight.empty())
        {
            cur = weight.top().second;
            if (!visited[cur])
            {
                minWeight = weight.top().first;
                break;
            }
            weight.pop();
        }
        result += minWeight;
        visited[cur] = true;
        for (auto edge : adj[cur])
        {
            weight.push(edge);
        }
    }
    return result;
}

int main()
{
    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    cout << prim(v);

    return 0;
}