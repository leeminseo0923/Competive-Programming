#include <iostream>
#include <utility>

using namespace std;

int Lagrange[50001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    Lagrange[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        Lagrange[i] = 5;
        for (int j = 1; j * j <= i; j++)
        {
            Lagrange[i] = min(Lagrange[i], Lagrange[i - j * j] + 1);
        }
    }

    cout << Lagrange[n];

    return 0;
}