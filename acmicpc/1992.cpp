#include <iostream>

using namespace std;

int map[64][64];

string quadTree(int startX, int startY, int endX, int endY)
{
    int startData = map[startY][startX];

    for (int y = startY; y < endY; y++)
    {
        for (int x = startX; x < endX; x++)
        {
            if (startData != map[y][x])
            {
                int midX = (endX + startX) / 2;
                int midY = (endY + startY) / 2;
                return "(" + quadTree(startX, startY, midX, midY) + quadTree(midX, startY, endX, midY) + quadTree(startX, midY, midX, endY) + quadTree(midX, midY, endX, endY) + ")";
            }
        }
    }
    return to_string(startData);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cin.get();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] = cin.get() - '0';
        }
        cin.get();
    }
    cout << quadTree(0, 0, n, n);

    return 0;
}