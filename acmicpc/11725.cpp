#include <bits/stdc++.h>

using namespace std;

int parent[1010101];
vector<vector<int>> link(1010101);
int visited[1010101];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        link[a].push_back(b);
        link[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int item : link[cur])
        {
            if (visited[item] == 0)
            {
                q.push(item);
                parent[item] = cur;
                visited[item] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << '\n';
    }

    return 0;
}