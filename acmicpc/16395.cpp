#include <bits/stdc++.h>

using namespace std;

int pascalDP[31][31];

int pascal(int a, int b)
{
    if (b == 1 || a == b)
    {
        return 1;
    }
    int res = 0;
    if (pascalDP[a][b] == 0)
    {
        res = pascal(a - 1, b - 1) + pascal(a - 1, b);
        pascalDP[a][b] = res;
    }
    else
    {
        res = pascalDP[a][b];
    }
    return res;
}

int main()
{
    int k, n;
    cin >> n >> k;
    cout << pascal(n, k);
}