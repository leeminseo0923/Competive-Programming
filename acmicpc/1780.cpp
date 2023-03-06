#include <iostream>

using namespace std;

int ctn[3];

int map[3000][3000];

void solve(int xStart, int yStart, int xEnd, int yEnd)
{
    int startNum = map[yStart][xStart];
    int flag = 0;
    for (int i = yStart; i < yEnd; i++)
    {
        for (int j = xStart; j < xEnd; j++)
        {
            if (map[i][j] != startNum)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    if (flag)
    {
        int side = (xEnd - xStart) / 3;
        solve(xStart, yStart, xStart + side, yStart + side);
        solve(xStart + side, yStart, xStart + side * 2, yStart + side);
        solve(xStart + side * 2, yStart, xEnd, yStart + side);

        solve(xStart, yStart + side, xStart + side, yStart + side * 2);
        solve(xStart + side, yStart + side, xStart + side * 2, yStart + side * 2);
        solve(xStart + side * 2, yStart + side, xEnd, yStart + side * 2);

        solve(xStart, yStart + side * 2, xStart + side, yEnd);
        solve(xStart + side, yStart + side * 2, xStart + side * 2, yEnd);
        solve(xStart + side * 2, yStart + side * 2, xEnd, yEnd);
    }
    else
    {
        ctn[startNum + 1]++;
    }
}

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
        {
            cin >> map[i][j];
        }
    }

    solve(0, 0, n, n);

    for (int i = 0; i < 3; i++)
    {
        cout << ctn[i] << '\n';
    }

    return 0;
}