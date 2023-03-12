#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[100][100];

int visited[100][100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    vector<vector<vector<char>>> c = {{{'R'}, {'G'}, {'B'}}, {{'R', 'G'}, {'B'}}};

    for (int i = 0; i < 2; i++)
    {
        vector<vector<char>> curCase(c[i]);
        int ctn = 0;

        for (int j = 0; j < curCase.size(); j++)
        {
            vector<char> curColorSet(curCase[j]);

            for (int y = 0; y < n; y++)
            {
                for (int x = 0; x < n; x++)
                {
                    queue<pair<int, int>> q;
                    for (int k = 0; k < curColorSet.size(); k++)
                    {
                        if (visited[y][x] == 0 && curColorSet[k] == map[y][x])
                        {
                            visited[y][x] = 1;
                            q.push(make_pair(x, y));
                        }
                    }

                    if (!q.empty())
                    {
                        ctn++;
                    }

                    while (!q.empty())
                    {
                        pair<int, int> cur = q.front();
                        q.pop();

                        int curX = cur.first;
                        int curY = cur.second;

                        for (int k = 0; k < curColorSet.size(); k++)
                        {
                            char curColor = curColorSet[k];
                            if (curX > 0 && visited[curY][curX - 1] == 0 && map[curY][curX - 1] == curColor)
                            {
                                visited[curY][curX - 1] = 1;
                                q.push(make_pair(curX - 1, curY));
                            }
                            if (curY > 0 && visited[curY - 1][curX] == 0 && map[curY - 1][curX] == curColor)
                            {
                                visited[curY - 1][curX] = 1;
                                q.push(make_pair(curX, curY - 1));
                            }
                            if (curX < n - 1 && visited[curY][curX + 1] == 0 && map[curY][curX + 1] == curColor)
                            {
                                visited[curY][curX + 1] = 1;
                                q.push(make_pair(curX + 1, curY));
                            }
                            if (curY < n - 1 && visited[curY + 1][curX] == 0 && map[curY + 1][curX] == curColor)
                            {
                                visited[curY + 1][curX] = 1;
                                q.push(make_pair(curX, curY + 1));
                            }
                        }
                    }
                }
            }
        }
        cout << ctn << ' ';
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                visited[y][x] = 0;
            }
        }
    }

    return 0;
}