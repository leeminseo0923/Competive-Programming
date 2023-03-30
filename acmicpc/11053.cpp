// 가장 긴 증가하는 부분 수열
#include <bits/stdc++.h>

using namespace std;
int a[1000];
int dp[1000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] < a[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    cout << *max_element(dp, dp + n);

    return 0;
}