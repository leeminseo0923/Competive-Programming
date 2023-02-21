#include <iostream>

using namespace std;

long long cases[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cases[0] = 1;
    cases[1] = 2;

    for (int i = 2; i < 1000; i++)
    {
        cases[i] = (cases[i - 2] + cases[i - 1]) % 10007;
    }

    int n;
    cin >> n;
    cout << cases[n - 1] % 10007;

    return 0;
}