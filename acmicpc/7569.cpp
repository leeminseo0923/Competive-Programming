#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[100][100][100];
int visited[100][100][100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n, h;

    cin >> m >> n >> h;

    queue<vector<int>> q;

    for (int z = 0; z < h; z++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                cin >> map[z][y][x];
                if (map[z][y][x] == 1)
                {
                    q.push({x, y, z});
                    visited[z][y][x] = 1;
                }
            }
        }
    }

    int ctn = 0;
    while (!q.empty())
    {
        int flag = 0;
        int iter = q.size();
        for (int i = 0; i < iter; i++)
        {
            vector<int> cur(q.front());
            q.pop();

            int x = cur[0];
            int y = cur[1];
            int z = cur[2];

            if (x > 0 && visited[z][y][x - 1] == 0 && map[z][y][x - 1] == 0)
            {
                flag = 1;
                visited[z][y][x - 1]++;
                map[z][y][x - 1]++;
                q.push({x - 1, y, z});
            }
            if (y > 0 && visited[z][y - 1][x] == 0 && map[z][y - 1][x] == 0)
            {
                flag = 1;
                visited[z][y - 1][x]++;
                map[z][y - 1][x]++;
                q.push({x, y - 1, z});
            }
            if (z > 0 && visited[z - 1][y][x] == 0 && map[z - 1][y][x] == 0)
            {
                flag = 1;
                visited[z - 1][y][x]++;
                map[z - 1][y][x]++;
                q.push({x, y, z - 1});
            }
            if (x < m - 1 && visited[z][y][x + 1] == 0 && map[z][y][x + 1] == 0)
            {
                flag = 1;
                visited[z][y][x + 1]++;
                map[z][y][x + 1]++;
                q.push({x + 1, y, z});
            }
            if (y < n - 1 && visited[z][y + 1][x] == 0 && map[z][y + 1][x] == 0)
            {
                flag = 1;
                visited[z][y + 1][x]++;
                map[z][y + 1][x]++;
                q.push({x, y + 1, z});
            }
            if (z < h - 1 && visited[z + 1][y][x] == 0 && map[z + 1][y][x] == 0)
            {
                flag = 1;
                visited[z + 1][y][x]++;
                map[z + 1][y][x]++;
                q.push({x, y, z + 1});
            }
        }
        if (flag)
        {
            ctn++;
        }
    }

    for (int z = 0; z < h; z++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (map[z][y][x] == 0)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << ctn;

    return 0;
}