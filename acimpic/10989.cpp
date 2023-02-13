#include <iostream>

using namespace std;

int a[10000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        short b;
        cin >> b;
        a[b - 1]++;
    }

    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < a[i]; j++)
        {
            cout << i + 1 << '\n';
        }
    }
    return 0;
}