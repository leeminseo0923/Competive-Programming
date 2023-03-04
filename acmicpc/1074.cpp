#include <iostream>

using namespace std;

int r, c, ctn;

bool flag;

void search(int startX, int endX, int startY, int endY)
{
    int len = endX - startX;
    int midX = len / 2 + startX;
    int midY = len / 2 + startY;

    if (flag == true)
        return;

    if (len == 1)
    {
        if (startX == c && startY == r)
        {
            cout << ctn << "\n";
            flag = true;
            return;
        }
        ctn++;
    }
    else
    {
        if (startX <= c && midX > c && startY <= r && midY > r)
            search(startX, midX, startY, midY);
        else
            ctn += (midX - startX) * (midY - startY);

        if (midX <= c && endX > c && startY <= r && midY > r)
            search(midX, endX, startY, midY);
        else
            ctn += (endX - midX) * (midY - startY);

        if (startX <= c && midX > c && midY <= r && endY > r)
            search(startX, midX, midY, endY);
        else
            ctn += (midX - startX) * (endY - midY);

        if (midX <= c && endX > c && midY <= r && endY > r)
            search(midX, endX, midY, endY);
        else
            ctn += (endX - midX) * (endY - midY);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n >> r >> c;

    int side = 1 << n;

    search(0, side, 0, side);

    return 0;
}