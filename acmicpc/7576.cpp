#include <iostream>

using namespace std;

int map[1000][1000];

int queue[1000 * 1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    int front = 0;
    int end = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                queue[end] = i * m + j;
                end++;
            }
        }
    }
    int time = end;
    int ctn = 0;
    int flag = 0;

    while (front < end)
    {
        int x = queue[front] % m;
        int y = queue[front] / m;

        if (x > 0 && map[y][x - 1] == 0)
        {
            map[y][x - 1] = 1;
            queue[end] = y * m + (x - 1);
            flag = 1;
            end++;
        }
        if (y > 0 && map[y - 1][x] == 0)
        {
            map[y - 1][x] = 1;
            queue[end] = (y - 1) * m + x;
            flag = 1;
            end++;
        }
        if (x < m - 1 && map[y][x + 1] == 0)
        {
            map[y][x + 1] = 1;
            queue[end] = y * m + (x + 1);
            flag = 1;
            end++;
        }
        if (y < n - 1 && map[y + 1][x] == 0)
        {
            map[y + 1][x] = 1;
            queue[end] = (y + 1) * m + x;
            flag = 1;
            end++;
        }

        front++;

        if (time == front && flag)
        {
            time = end;
            flag = 0;
            ctn++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }

    cout << ctn;

    return 0;
}