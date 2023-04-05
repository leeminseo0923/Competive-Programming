#include <bits/stdc++.h>

using namespace std;

int tree[200000];

int dp[200000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < (n * (n + 1)) / 2; i++)
    {
        cin >> tree[i];
    }

    dp[0] = tree[0];

    int level = 1;
    int ctn = 0;

    for (int i = 0; i < (n * (n + 1)) / 2; i++)
    {
        dp[i + level] = max(dp[i + level], dp[i] + tree[i + level]);
        dp[i + level + 1] = max(dp[i + level + 1], dp[i] + tree[i + level + 1]);
        ctn++;
        if (ctn >= level)
        {
            level++;
            ctn = 0;
        }
    }

    cout << *max_element(dp + (n * (n - 1)) / 2, dp + (n * (n + 1)) / 2);

    return 0;
}