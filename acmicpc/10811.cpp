#include <iostream>

using namespace std;

int basket[101];

int main()
{
    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        basket[i] = i;
    }

    while (m--)
    {
        int i, j;
        cin >> i >> j;

        for (int k = 0; k < (j - i + 1) / 2; k++)
        {
            int temp = basket[i + k];
            basket[i + k] = basket[j - k];
            basket[j - k] = temp;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << basket[i] << ' ';
    }

    return 0;
}