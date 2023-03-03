#include <iostream>

using namespace std;

int white, blue;

int map[128][128];

void countWB(int startX, int startY, int endX, int endY)
{
    int start = map[startX][startY];
    for (int x = startX; x < endX; x++)
    {
        for (int y = startY; y < endY; y++)
        {
            if (map[x][y] != start)
            {
                countWB(startX, startY, (startX + endX) / 2, (startY + endY) / 2);
                countWB(startX, (startY + endY) / 2, (startX + endX) / 2, endY);
                countWB((startX + endX) / 2, startY, endX, (startY + endY) / 2);
                countWB((startX + endX) / 2, (startY + endY) / 2, endX, endY);
                return;
            }
        }
    }
    if (start == 0)
    {
        white++;
        return;
    }
    else
    {
        blue++;
        return;
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

    countWB(0, 0, n, n);

    cout << white << '\n'
         << blue;

    return 0;
}