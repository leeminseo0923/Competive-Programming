#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> people(101);

    int minKevinIdx = 0;
    int minKevin = 9999;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        people[a].push_back(b);
        people[b].push_back(a);
    }

    int visited[101];
    for (int j = 1; j < 101; j++)
    {
        if (people[j].empty())
        {
            continue;
        }
        for (int i = 0; i < 101; i++)
        {
            visited[i] = 0;
        }
        int curKevin = 0;
        queue<int> que;

        visited[j] = 1;
        que.push(j);

        int ctn = 0;

        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                int cur = que.front();
                que.pop();
                curKevin += ctn;
                for (int l = 0; l < people[cur].size(); l++)
                {
                    if (visited[people[cur][l]] == 0)
                    {
                        visited[people[cur][l]] = 1;
                        que.push(people[cur][l]);
                    }
                }
            }
            ctn++;
        }

        if (minKevin > curKevin)
        {
            minKevin = curKevin;
            minKevinIdx = j;
        }
    }

    cout << minKevinIdx;
    return 0;
}