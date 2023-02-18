#include <iostream>
#include <numeric>
using namespace std;

long long villa[14][14];

long long mySum(long long *start, long long *end)
{
    long long result = 0;
    for (int i = 0; i < end - start; i++)
    {
        result += *(start + i);
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                long long s = 0;
                if (i > 0)
                {
                    if (j > 0)
                        s = mySum(&villa[i - 1][0], &villa[i - 1][j] + 1);
                    else
                        s = villa[i - 1][0];
                }
                else
                {
                    s = (j + 1) * (j + 2) / 2;
                }
                villa[i][j] = s;
            }
        }
        cout << villa[k - 1][n - 1] << '\n';
    }
    return 0;
}