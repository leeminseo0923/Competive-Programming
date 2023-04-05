#include <bits/stdc++.h>

using namespace std;

int house[1000][3];
int dp[1000][3];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> house[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        dp[0][i] = house[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = min(dp[i - 1][(j + 4) % 3], dp[i - 1][(j + 2) % 3]) + house[i][j];
        }
    }

    cout << *min_element(dp[n - 1], dp[n - 1] + 3);

    return 0;
}