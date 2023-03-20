#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, m;
    cin >> a >> b >> c >> m;

    int cur = 0;
    int t = 0;
    const int MAX_TIME = 24;

    int res = 0;

    while (t < MAX_TIME)
    {
        t++;
        if (m < a + cur)
        {
            cur -= c;
            if (cur < 0)
            {
                cur = 0;
            }
        }
        else
        {
            cur += a;
            res += b;
        }
    }

    cout << res;

    return 0;
}