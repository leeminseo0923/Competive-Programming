#include <bits/stdc++.h>

using namespace std;

int chae[300000];

int main()
{
    for (int i = 2; i * i <= 248000; i++)
    {
        for (int j = 2; j * i <= 248000; j++)
        {
            chae[i * j] = 1;
        }
    }
    int n;
    cin >> n;

    while (n > 0)
    {
        int sum = 0;
        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (!chae[i])
            {
                sum++;
            }
        }
        cout << sum << '\n';

        cin >> n;
    }
    return 0;
}