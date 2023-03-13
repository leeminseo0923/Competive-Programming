#include <bits/stdc++.h>

using namespace std;

int visited[10000];

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        for (int i = 0; i < 10000; i++)
        {
            visited[i] = 0;
        }

        int a, b;
        cin >> a >> b;

        queue<pair<string, int>> q;
        q.push(make_pair("", a));
        visited[a] = 1;

        while (!q.empty())
        {
            pair<string, int> cur = q.front();
            string curStr = cur.first;
            int curNum = cur.second;

            if (curNum == b)
            {
                cout << curStr << '\n';
                break;
            }

            q.pop();

            int makeNum = curNum * 2 % 10000;
            if (!visited[makeNum])
            {
                q.push(make_pair(curStr + "D", makeNum));
                visited[makeNum]++;
            }
            makeNum = curNum == 0 ? 9999 : curNum - 1;
            if (!visited[makeNum])
            {
                q.push(make_pair(curStr + "S", makeNum));
                visited[makeNum]++;
            }
            makeNum = (curNum % 1000) * 10 + curNum / 1000;
            if (!visited[makeNum])
            {
                q.push(make_pair(curStr + "L", makeNum));
                visited[makeNum]++;
            }
            makeNum = (curNum % 10) * 1000 + curNum / 10;
            if (!visited[makeNum])
            {
                q.push(make_pair(curStr + "R", makeNum));
                visited[makeNum]++;
            }
        }
    }
    return 0;
}