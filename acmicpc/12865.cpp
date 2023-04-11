#include <bits/stdc++.h>

using namespace std;

int dp[101][1010101];

int weight[101];
int value[101];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j - weight[i] >= 0)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][k];

    return 0;
}