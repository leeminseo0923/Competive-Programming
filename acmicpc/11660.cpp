#include <bits/stdc++.h>

using namespace std;

int table[1024][1024];

int sumTable[1024][1024];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> table[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && j > 0)
            {
                sumTable[i][j] += sumTable[i - 1][j] + sumTable[i][j - 1] - sumTable[i - 1][j - 1];
            }
            else if (i > 0)
            {
                sumTable[i][j] += sumTable[i - 1][j];
            }
            else if (j > 0)
            {
                sumTable[i][j] += sumTable[i][j - 1];
            }
            sumTable[i][j] += table[i][j];
        }
    }

    while (m--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int res = 0;
        res += sumTable[x2 - 1][y2 - 1];
        if (x1 > 1)
        {
            res -= sumTable[x1 - 2][y2 - 1];
        }
        if (y1 > 1)
        {
            res -= sumTable[x2 - 1][y1 - 2];
        }
        if (y1 > 1 && x1 > 1)
        {
            res += sumTable[x1 - 2][y1 - 2];
        }
        cout << res << '\n';
    }

    return 0;
}