#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    int maxWin = log2(n);

    int canWin = log2(k) + m;

    cout << min(canWin, maxWin);

    return 0;
}