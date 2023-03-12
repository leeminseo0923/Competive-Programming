#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int mid = 2 * i + 1;

        int space = n - 1 - i;

        for (int j = 0; j < space; j++)
        {
            cout << ' ';
        }
        for (int j = 0; j < mid; j++)
        {
            cout << '*';
        }
        cout << '\n';
    }

    for (int i = n - 2; i >= 0; i--)
    {
        int tot = 2 * n - 1;
        int mid = 2 * i + 1;

        int space = n - 1 - i;

        for (int j = 0; j < space; j++)
        {
            cout << ' ';
        }
        for (int j = 0; j < mid; j++)
        {
            cout << '*';
        }
        if (i)
            cout << '\n';
    }

    return 0;
}