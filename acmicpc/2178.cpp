#include <iostream>
#include <queue>
#include <utility>

using namespace std;

bool map[100][100];
bool visited[100][100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;

    int ctn = 1;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            pair<int, int> cur = q.front();
            if (cur.first == n - 1 && cur.second == m - 1)
            {
                cout << ctn;
                return 0;
            }
            q.pop();
            if (cur.first > 0 && map[cur.first - 1][cur.second] == 1 && visited[cur.first - 1][cur.second] == 0)
            {
                q.push(make_pair(cur.first - 1, cur.second));
                visited[cur.first - 1][cur.second] = 1;
            }
            if (cur.second > 0 && map[cur.first][cur.second - 1] == 1 && visited[cur.first][cur.second - 1] == 0)
            {
                q.push(make_pair(cur.first, cur.second - 1));
                visited[cur.first][cur.second - 1] = 1;
            }
            if (cur.first < n - 1 && map[cur.first + 1][cur.second] == 1 && visited[cur.first + 1][cur.second] == 0)
            {
                q.push(make_pair(cur.first + 1, cur.second));
                visited[cur.first + 1][cur.second] = 1;
            }
            if (cur.second < m - 1 && map[cur.first][cur.second + 1] == 1 && visited[cur.first][cur.second + 1] == 0)
            {
                q.push(make_pair(cur.first, cur.second + 1));
                visited[cur.first][cur.second + 1] = 1;
            }
        }
        ctn++;
    }

    cout << ctn;

    return 0;
}