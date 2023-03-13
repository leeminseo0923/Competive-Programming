#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int map[100];
int link[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i < 7; i++)
    {
        map[i] = 1;
    }
    for (int i = 7; i < 100; i++)
    {
        map[i] = 999;
    }

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        link[x - 1] = y - 1;
        map[x - 1] = -1;
    }

    for (int i = n; i < m + n; i++)
    {
        int u, v;
        cin >> u >> v;
        link[u - 1] = v - 1;
        map[u - 1] = -1;
    }

    queue<int> q;

    for (int i = 1; i <= 6; i++)
    {
        if (map[i] == 1)
        {
            q.push(i);
        }
        else if (map[i] == -1)
        {
            map[link[i]] = 1;
            q.push(link[i]);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            if (cur + i < 100 && map[cur + i] == -1)
            {
                if (map[link[cur + i]] > map[cur] + 1)
                {
                    q.push(link[cur + i]);
                    map[link[cur + i]] = map[cur] + 1;
                }
            }
            else
            {
                if (cur + i < 100 && map[cur + i] > map[cur] + 1)
                {
                    q.push(cur + i);
                    map[cur + i] = map[cur] + 1;
                }
            }
        }
    }

    cout << map[99];

    return 0;
}