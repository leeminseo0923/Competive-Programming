#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> basket;
    for (int i = 1; i <= n; i++)
    {
        basket.push_back(i);
    }

    int m;
    cin >> m;

    while (m--)
    {
        int i, j, k;
        cin >> i >> j >> k;

        rotate(basket.begin() + i - 1, basket.begin() + k - 1, basket.begin() + j);
    }
    for (int i = 0; i < n; i++)
    {
        cout << basket[i] << ' ';
    }

    return 0;
}