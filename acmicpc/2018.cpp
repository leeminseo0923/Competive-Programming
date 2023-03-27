#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int ctn = 0;

    for (int k = 1; k <= n; k++)
    {
        if ((2 * n + k * k - k) % (2 * k) == 0)
        {
            int a = (2 * n + k * k - k) / (2 * k);
            if (k <= a)
            {
                ctn++;
            }
        }
    }

    cout << ctn;

    return 0;
}