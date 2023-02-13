#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int coin[n];

    for (int i = 0; i < n; i++)
    {
        cin >> coin[n - i - 1];
    }

    int ctn = 0;

    while (k > 0)
    {
        for (int i = 0; i < n; i++)
        {
            ctn += k / coin[i];
            k %= coin[i];
        }
    }

    cout << ctn;

    return 0;
}