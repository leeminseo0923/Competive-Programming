#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int res = 1;
    int div = 1;

    int c = min(k, (n - k));
    int p = c;
    for (int i = 0; i < c; i++)
    {
        res *= n--;
        div *= p--;
    }

    cout << res / div << endl;
    return 0;
}