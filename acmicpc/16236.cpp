#include <bits/stdc++.h>

using namespace std;

int sea[20][20];
int visited[20][20];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> sea[i][j];
            if (sea[i][j] == 9)
            {
                q.push(make_pair(j, i));
            }
        }
    }

    int curSize = 2;

    int flag = 1;

    int time = 0;

    while (flag)
    {
        flag = 0;
        int startX, startY;
        pair<int, int> start = q.front();
        startX = start.first;
        startY = start.second;
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();

            int curX = cur.first;
            int curY = cur.second;

            if (sea[curY][curX] < curSize && sea[curY][curX] > 0)
            {
                curSize++;
                flag = 1;
                q = queue<pair<int, int>>();
                sea[curY][curX] = 0;
                q.push(make_pair(curX, curY));
                time += abs(startX - curX) + abs(startY - curY);
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        visited[i][j] = 0;
                    }
                }
                visited[curY][curX] = 1;
                break;
            }

            if (curX > 0 && sea[curY][curX - 1] <= curSize && not visited[curY][curX - 1])
            {
                q.push(make_pair(curX - 1, curY));
                visited[curY][curX - 1]++;
            }

            if (curY > 0 && sea[curY - 1][curX] <= curSize && not visited[curY - 1][curX])
            {
                q.push(make_pair(curX, curY - 1));
                visited[curY - 1][curX]++;
            }

            if (curX < n - 1 && sea[curY][curX + 1] <= curSize && not visited[curY][curX + 1])
            {
                q.push(make_pair(curX + 1, curY));
                visited[curY][curX + 1]++;
            }

            if (curY < n - 1 && sea[curY + 1][curX] <= curSize && not visited[curY + 1][curX])
            {
                q.push(make_pair(curX, curY + 1));
                visited[curY + 1][curX]++;
            }
        }
    }

    cout << time;
    return 0;
}