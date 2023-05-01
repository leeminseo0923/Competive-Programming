#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[10101];

int maxRadius;

int dfs(int curNode)
{
    int maxWeight[2] = {0, 0};

    for (auto child : graph[curNode])
    {
        int childNode = child.first;
        int childWeight = child.second;

        int sumWeight = dfs(childNode) + childWeight;

        int temp = min(sumWeight, maxWeight[0]);
        maxWeight[0] = max(maxWeight[0], sumWeight);

        maxWeight[1] = max(maxWeight[1], temp);
    }

    maxRadius = max(maxRadius, maxWeight[0] + maxWeight[1]);

    return maxWeight[0];
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int parent, child, weight;
        cin >> parent >> child >> weight;

        graph[parent].push_back({child, weight});
    }

    dfs(1);

    cout << maxRadius;

    return 0;
}