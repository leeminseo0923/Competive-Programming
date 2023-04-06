#include <bits/stdc++.h>

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
        int n;
        cin >> n;
        int score[n][2];
        int dp[n][3];
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < n; i++)
            {
                cin >> score[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                dp[i][j] = 0;
            }
        }

        dp[0][0] = score[0][0];
        dp[0][1] = score[0][1];

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][2] + score[i][0], dp[i - 1][1] + score[i][0]);
            dp[i][1] = max(dp[i - 1][2] + score[i][1], dp[i - 1][0] + score[i][1]);
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
        }

        cout << *max_element(dp[n - 1], dp[n - 1] + 3) << '\n';
    }
    return 0;
}