#include <bits/stdc++.h>
#define MAX_TIME 100001

using namespace std;

int minTime[1010101];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < 1010101; i++)
    {
        minTime[i] = MAX_TIME;
    }

    queue<pair<int, int>> q;

    q.push(make_pair(n, 0));
    minTime[n] = 0;

    while (!q.empty())
    {
        int num = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (num < k && cnt < minTime[num * 2])
        {
            minTime[num * 2] = cnt;
            q.push(make_pair(num * 2, cnt));
        }
        if (num > 0 && cnt + 1 < minTime[num - 1])
        {
            minTime[num - 1] = cnt + 1;
            q.push(make_pair(num - 1, cnt + 1));
        }
        if (num < k && cnt + 1 < minTime[num + 1])
        {
            minTime[num + 1] = cnt + 1;
            q.push(make_pair(num + 1, cnt + 1));
        }
    }

    cout << minTime[k];
    return 0;
}