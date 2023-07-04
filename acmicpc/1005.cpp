#include <iostream>
#include <vector>
#include <queue>
#define INF 200000000

using namespace std;

int times[1000];
bool visited[1000];
int sum_times[1000];
int w, n, k;

int find_next(queue<int> &q, vector<int> &cnt, bool is_start)
{
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] == 0 && !visited[i])
        {
            if (i == w)
                return 1;
            q.push(i);
            visited[i] = true;
            if (is_start)
                sum_times[i] = times[i];
        }
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> times[i];
            sum_times[i] = 0;
            visited[i] = false;
        }
        vector<int> sequence[1000];
        vector<int> cnt(1000, 0);

        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;

            sequence[x].push_back(y);
            cnt[y]++;
        }

        queue<int> q;
        cin >> w;
        w--;

        int isFind = find_next(q, cnt, true);

        if (isFind)
        {
            cout << times[w] << '\n';
            continue;
        }

        while (!isFind)
        {
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();

                while (!sequence[cur].empty())
                {
                    int next = sequence[cur].back();
                    cnt[next]--;
                    sum_times[next] = max(sum_times[next], times[next] + sum_times[cur]);

                    sequence[cur].pop_back();
                }
            }

            isFind = find_next(q, cnt, false);
        }

        cout << sum_times[w] << "\n";
    }
    return 0;
}