#include <bits/stdc++.h>

using namespace std;

int dp[3][1010101] = {{0, 0, 2}, {0, 1, 2}, {0, 1, 2}};

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    cout << (int)(2 * pow(3, n - 2));
    return 0;
}