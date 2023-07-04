#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

char campus[600][600];
bool visited[600][600];

int main()
{
    int n, m;
    cin >> n >> m;
    getchar();

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            campus[i][j] = getchar();
            if (campus[i][j] == 'I')
            {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
        getchar();
    }
    int count = 0;

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if (i > 0 && !visited[i - 1][j] && campus[i - 1][j] != 'X')
        {
            visited[i - 1][j] = true;
            q.push({i - 1, j});
            if (campus[i - 1][j] == 'P')
                count++;
        }
        if (i < n - 1 && !visited[i + 1][j] && campus[i + 1][j] != 'X')
        {
            visited[i + 1][j] = true;
            q.push({i + 1, j});
            if (campus[i + 1][j] == 'P')
                count++;
        }
        if (j > 0 && !visited[i][j - 1] && campus[i][j - 1] != 'X')
        {
            visited[i][j - 1] = true;
            q.push({i, j - 1});
            if (campus[i][j - 1] == 'P')
                count++;
        }
        if (j < m - 1 && !visited[i][j + 1] && campus[i][j + 1] != 'X')
        {
            visited[i][j + 1] = true;
            q.push({i, j + 1});
            if (campus[i][j + 1] == 'P')
                count++;
        }
    }

    if (count == 0)
        cout << "TT";
    else
        cout << count;

    return 0;
}