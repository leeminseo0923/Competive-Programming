#include <iostream>
#include <queue>

using namespace std;

int map[1000][1000];

int outmap[1000][1000];

bool visited[1000][1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {

        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        int curDist = outmap[y][x] + 1;

        if (x > 0 && map[y][x - 1] == 1 && outmap[y][x - 1] == 0)
        {
            q.push({y, x - 1});
            outmap[y][x - 1] = curDist;
        }
        if (y > 0 && map[y - 1][x] == 1 && outmap[y - 1][x] == 0)
        {
            q.push({y - 1, x});
            outmap[y - 1][x] = curDist;
        }
        if (x < m - 1 && map[y][x + 1] == 1 && outmap[y][x + 1] == 0)
        {
            q.push({y, x + 1});
            outmap[y][x + 1] = curDist;
        }
        if (y < n - 1 && map[y + 1][x] == 1 && outmap[y + 1][x] == 0)
        {
            q.push({y + 1, x});
            outmap[y + 1][x] = curDist;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (outmap[i][j] > 0)
                cout << outmap[i][j];
            else
            {
                if (map[i][j] == 2)
                {
                    cout << 0;
                }
                else if (map[i][j] == 1)
                {
                    cout << -1;
                }
                else
                {
                    cout << 0;
                }
            }

            if (j < m - 1)
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}