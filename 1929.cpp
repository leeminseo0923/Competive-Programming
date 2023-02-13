#include <iostream>

using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    for (int i = m; i <= n; i++)
    {
        if (i == 1)
        {
            continue;
        }
        if (isPrime(i))
        {
            cout << i << '\n';
        }
    }
    return 0;
}