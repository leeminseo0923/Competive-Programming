#include <iostream>
#include <vector>
#include <queue>
#define INF 1001

using namespace std;

vector<pair<int, int>> adj[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> weight;
bool visited[1000001];

int prim(int v)
{
    int result = 0;
    weight.push({0, 1});
    int maxWeight = 0;
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
        maxWeight = max(maxWeight, minWeight);
        visited[cur] = true;
        for (auto edge : adj[cur])
        {
            weight.push(edge);
        }
    }
    return result - maxWeight;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    cout << prim(n);

    return 0;
}