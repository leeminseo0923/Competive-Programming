#include <iostream>

using namespace std;

int fibArr[41];

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        if (fibArr[n - 2] < 0)
        {
            fibArr[n - 2] = fibonacci(n - 2);
        }
        if (fibArr[n - 1] < 0)
        {
            fibArr[n - 1] = fibonacci(n - 1);
        }
        fibArr[n] = fibArr[n - 1] + fibArr[n - 2];
        return fibArr[n - 1] + fibArr[n - 2];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 41; i++)
    {
        fibArr[i] = -1;
    }
    fibArr[0] = 0;
    fibArr[1] = 1;

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            cout << "1 0\n";
        }
        else
        {
            fibonacci(n);
            cout << fibArr[n - 1] << " " << fibArr[n] << "\n";
        }
    }

    return 0;
}