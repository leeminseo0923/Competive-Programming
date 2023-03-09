#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int maximum = lcm(m, n);

        int i, j;
        i = j = 0;
        int flag = 1;
        while (x + i * m != y + j * n)
        {
            if (x + i * m > maximum || y + j * n > maximum)
            {
                flag = 0;
                cout << -1 << '\n';
                break;
            }
            if (x + i * m > y + j * n)
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        if (flag)
        {
            cout << x + i * m << '\n';
        }
    }
}