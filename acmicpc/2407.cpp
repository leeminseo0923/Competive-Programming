#include <bits/stdc++.h>

using namespace std;

string pascalDP[110][110];

string sumString(string a, string b)
{
    string res = "";

    int c = 0;

    int i;
    while (!a.empty() || !b.empty() || c > 0)
    {
        if (!a.empty())
        {
            c += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty())
        {
            c += b.back() - '0';
            b.pop_back();
        }
        res.push_back((c % 10) + '0');
        c /= 10;
    }

    reverse(res.begin(), res.end());

    return res;
}

string pascal(int a, int b)
{
    if (b == 0 || a == b)
    {
        return "1";
    }
    string res = "";
    if (pascalDP[a][b] == "")
    {
        res = sumString(pascal(a - 1, b - 1), pascal(a - 1, b));
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
    int n, m;
    cin >> n >> m;

    m = min(n - m, m);

    cout << pascal(n, m);

    return 0;
}