#include <iostream>

using namespace std;

int basket[101];
int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int i, j, k;
        cin >> i >> j >> k;
        for (int a = i; a <= j; a++)
        {
            basket[a] = k;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << basket[i] << ' ';
    }

    return 0;
}