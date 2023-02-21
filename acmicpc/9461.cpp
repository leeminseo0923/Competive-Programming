#include <iostream>

using namespace std;

long long p[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    p[0] = 1;
    p[1] = 1;
    p[2] = 1;
    p[3] = 2;
    p[4] = 2;

    for (int i = 5; i < 100; i++)
    {
        p[i] = p[i - 5] + p[i - 1];
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        cout << p[n - 1] << '\n';
    }

    return 0;
}