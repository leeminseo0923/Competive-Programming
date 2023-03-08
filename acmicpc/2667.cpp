#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int map[25][25];
int visited[25][25];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.get();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] = cin.get() - '0';
        }
        cin.get();
    }

    queue<pair<int, int>> q;

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1 && visited[i][j] == 0)
            {
                int ctn = 0;
                q.push(make_pair(i, j));
                visited[i][j] = 1;

                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    ctn++;

                    if (cur.first > 0 && map[cur.first - 1][cur.second] == 1 && visited[cur.first - 1][cur.second] == 0)
                    {
                        visited[cur.first - 1][cur.second] = 1;
                        q.push(make_pair(cur.first - 1, cur.second));
                    }
                    if (cur.second > 0 && map[cur.first][cur.second - 1] == 1 && visited[cur.first][cur.second - 1] == 0)
                    {
                        visited[cur.first][cur.second - 1] = 1;
                        q.push(make_pair(cur.first, cur.second - 1));
                    }
                    if (cur.first < n - 1 && map[cur.first + 1][cur.second] == 1 && visited[cur.first + 1][cur.second] == 0)
                    {
                        visited[cur.first + 1][cur.second] = 1;
                        q.push(make_pair(cur.first + 1, cur.second));
                    }
                    if (cur.second < n - 1 && map[cur.first][cur.second + 1] == 1 && visited[cur.first][cur.second + 1] == 0)
                    {
                        visited[cur.first][cur.second + 1] = 1;
                        q.push(make_pair(cur.first, cur.second + 1));
                    }
                }
                ans.push_back(ctn);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}