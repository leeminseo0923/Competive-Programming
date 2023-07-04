#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001];
bool visited[1001][1001];
bool crashVisited[1001][1001];

int main()
{
    int n, m;
    cin >> n >> m;

    cin.get();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map[i][j] = cin.get() - '0';
        }
        cin.get();
    }

    queue<pair<pair<int, int>, pair<int, bool>>> q;
    q.push({{0, 0}, {1, false}});

    while (!q.empty())
    {
        int i = q.front().first.first;
        int j = q.front().first.second;

        int cnt = q.front().second.first;
        if (i == n - 1 && j == m - 1)
        {
            cout << cnt;
            return 0;
        }
        bool crashed = q.front().second.second;
        q.pop();

        if (crashed)
        {
            if (i > 0 && map[i - 1][j] == 0 && !crashVisited[i - 1][j])
            {
                crashVisited[i - 1][j] = true;
                q.push({{i - 1, j}, {cnt + 1, crashed}});
            }
            if (i < n - 1 && map[i + 1][j] == 0 && !crashVisited[i + 1][j])
            {
                crashVisited[i + 1][j] = true;
                q.push({{i + 1, j}, {cnt + 1, crashed}});
            }
            if (j > 0 && map[i][j - 1] == 0 && !crashVisited[i][j - 1])
            {
                crashVisited[i][j - 1] = true;
                q.push({{i, j - 1}, {cnt + 1, crashed}});
            }
            if (j < m - 1 && map[i][j + 1] == 0 && !crashVisited[i][j + 1])
            {
                crashVisited[i][j + 1] = true;
                q.push({{i, j + 1}, {cnt + 1, crashed}});
            }
        }
        else
        {
            if (i > 0 && !visited[i - 1][j])
            {
                if (map[i - 1][j])
                {
                    crashVisited[i - 1][j] = true;
                    q.push({{i - 1, j}, {cnt + 1, true}});
                }
                else
                {
                    visited[i - 1][j] = true;
                    crashVisited[i - 1][j] = true;
                    q.push({{i - 1, j}, {cnt + 1, crashed}});
                }
            }
            if (i < n - 1 && !visited[i + 1][j])
            {
                if (map[i + 1][j])
                {
                    crashVisited[i + 1][j] = true;
                    q.push({{i + 1, j}, {cnt + 1, true}});
                }
                else
                {
                    visited[i + 1][j] = true;
                    crashVisited[i + 1][j] = true;
                    q.push({{i + 1, j}, {cnt + 1, crashed}});
                }
            }
            if (j > 0 && !visited[i][j - 1])
            {
                if (map[i][j - 1])
                {
                    crashVisited[i][j - 1] = true;
                    q.push({{i, j - 1}, {cnt + 1, true}});
                }
                else
                {
                    visited[i][j - 1] = true;
                    crashVisited[i][j - 1] = true;
                    q.push({{i, j - 1}, {cnt + 1, crashed}});
                }
            }
            if (j < m - 1 && !visited[i][j + 1])
            {
                if (map[i][j + 1])
                {
                    crashVisited[i][j + 1] = true;
                    q.push({{i, j + 1}, {cnt + 1, true}});
                }
                else
                {
                    visited[i][j + 1] = true;
                    crashVisited[i][j + 1] = true;
                    q.push({{i, j + 1}, {cnt + 1, crashed}});
                }
            }
        }
    }

    cout << -1;

    return 0;
}