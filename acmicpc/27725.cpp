#include <bits/stdc++.h>

using namespace std;

int p[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    long long k;
    cin >> k;

    long long res = 0;

    for (int i = 0; i < n; i++)
    {
        long long cur = p[i];

        while (k / cur > 0)
        {
            res += k / cur;
            cur *= p[i];
        }
    }

    cout << res;

    return 0;
}