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
                sea[i][j] = 0;
                visited[i][j] = 1;
            }
        }
    }

    int curSize = 2;
    int catchFish = 0;

    int flag = 1;

    int time = 0;

    while (flag)
    {
        flag = 0;
        int startX, startY;
        pair<int, int> start = q.front();
        startX = start.first;
        startY = start.second;

        pair<int, int> des = make_pair(n, n);
        int isCatch = 0;
        int t = 0;
        while (!q.empty() && !isCatch)
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                pair<int, int> cur = q.front();
                q.pop();

                int curX = cur.first;
                int curY = cur.second;

                if (sea[curY][curX] < curSize && sea[curY][curX] > 0)
                {
                    isCatch = 1;
                    flag = 1;
                    if (curY < des.second)
                    {
                        des.second = curY;
                        des.first = curX;
                    }
                    else if (curY == des.second && curX < des.first)
                    {
                        des.second = curY;
                        des.first = curX;
                    }
                    continue;
                }
                if (!isCatch)
                {
                    if (curY > 0 && sea[curY - 1][curX] <= curSize && not visited[curY - 1][curX])
                    {
                        q.push(make_pair(curX, curY - 1));
                        visited[curY - 1][curX]++;
                    }
                    if (curX > 0 && sea[curY][curX - 1] <= curSize && not visited[curY][curX - 1])
                    {
                        q.push(make_pair(curX - 1, curY));
                        visited[curY][curX - 1]++;
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
            t++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }
        if (isCatch)
        {
            q = queue<pair<int, int>>();
            sea[des.second][des.first] = 0;
            q.push(make_pair(des.first, des.second));
            time += t - 1;
            catchFish++;
            if (catchFish >= curSize)
            {
                catchFish = 0;
                curSize++;
            }
        }
    }

    cout << time;
    return 0;
}