#include <iostream>

using namespace std;

int main()
{
    int basket[101];
    for (int i = 1; i <= 100; i++)
    {
        basket[i] = i;
    }

    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int i, j;
        cin >> i >> j;
        int temp = basket[i];
        basket[i] = basket[j];
        basket[j] = temp;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << basket[i] << ' ';
    }
    return 0;
}