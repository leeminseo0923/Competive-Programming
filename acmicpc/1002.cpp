#include <bits/stdc++.h>

using namespace std;

double getDistance(int x1, int y1, int x2, int y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double dis = getDistance(x1, y1, x2, y2);
        if (dis < 1)
        {
            if (r1 == r2)
            {
                if (r1 == 0)
                    cout << 1 << '\n';
                else
                    cout << -1 << '\n';
            }
            else
                cout << 0 << '\n';
        }
        else
        {
            if (dis < r1 + r2)
            {
                if (r1 + dis < r2 || r2 + dis < r1)
                    cout << 0 << '\n';
                else if (r1 + dis == r2 || r2 + dis == r1)
                    cout << 1 << '\n';
                else
                    cout << 2 << '\n';
            }
            else if (dis > r1 + r2)
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << 1 << '\n';
            }
        }
    }

    return 0;
}