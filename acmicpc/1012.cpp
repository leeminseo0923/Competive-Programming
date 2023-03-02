#include <iostream>
#include <queue>
using namespace std;

struct link
{
    bool cabbage = false;
    bool visited = false;
    char cLink = 0;
    struct link *linked[4] = {
        nullptr,
    };
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int m, n, k;
        cin >> m >> n >> k;
        struct link ground[m][n];

        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            ground[x][y].cabbage = true;
            if (x < m - 1 && ground[x + 1][y].cabbage)
            {
                ground[x][y].linked[ground[x][y].cLink] = &ground[x + 1][y];
                ground[x + 1][y].linked[ground[x + 1][y].cLink] = &ground[x][y];
                ground[x][y].cLink++;
                ground[x + 1][y].cLink++;
            }
            if (x > 0 && ground[x - 1][y].cabbage)
            {
                ground[x][y].linked[ground[x][y].cLink] = &ground[x - 1][y];
                ground[x - 1][y].linked[ground[x - 1][y].cLink] = &ground[x][y];
                ground[x][y].cLink++;
                ground[x - 1][y].cLink++;
            }
            if (y < n - 1 && ground[x][y + 1].cabbage)
            {
                ground[x][y].linked[ground[x][y].cLink] = &ground[x][y + 1];
                ground[x][y + 1].linked[ground[x + 1][y].cLink] = &ground[x][y];
                ground[x][y].cLink++;
                ground[x][y + 1].cLink++;
            }
            if (y > 0 && ground[x][y - 1].cabbage)
            {
                ground[x][y].linked[ground[x][y].cLink] = &ground[x][y - 1];
                ground[x][y - 1].linked[ground[x][y - 1].cLink] = &ground[x][y];
                ground[x][y].cLink++;
                ground[x][y - 1].cLink++;
            }
        }

        int res = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ground[i][j].cabbage == true && ground[i][j].visited == false)
                {
                    res++;
                    queue<struct link *> q;
                    q.push(&ground[i][j]);
                    struct link *cur = q.front();
                    cur->visited = true;
                    while (!q.empty())
                    {
                        q.pop();
                        for (int k = 0; k < cur->cLink; k++)
                        {
                            if (cur->linked[k]->visited == false)
                            {
                                cur->linked[k]->visited = true;
                                q.push(cur->linked[k]);
                            }
                        }
                        cur = q.front();
                    }
                }
            }
        }
        cout << res << "\n";
    }

    return 0;
}