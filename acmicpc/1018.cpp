#include <iostream>
#include <string.h>

using namespace std;

char board[50][50];
int N, M;

int countPart(int endX, int endY, char startColor)
{
    int count = 0;

    int startX, startY;
    startX = endX - 8;
    startY = endY - 8;

    for (int i = startY; i < endY; i++)
    {
        for (int j = startX; j < endX; j++)
        {
            if (board[i][j] != startColor)
            {
                count++;
            }
            startColor = startColor == 'W' ? 'B' : 'W';
        }
        startColor = startColor == 'W' ? 'B' : 'W';
    }

    return count;
}

int main()
{

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = temp[j];
        }
    }

    int endX = 8;
    int endY = 8;

    int minRepaint = 50 * 50;

    while (endY <= N)
    {
        while (endX <= M)
        {
            int temp = min(countPart(endX, endY, 'W'), countPart(endX, endY, 'B'));
            minRepaint = min(temp, minRepaint);
            endX++;
        }
        endX = 8;
        endY++;
    }

    cout << minRepaint;
}