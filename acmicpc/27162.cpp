#include <bits/stdc++.h>

using namespace std;

int cases[12];
int c[7];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string can;
    cin >> can;

    for (int i = 0; i < can.size(); i++)
    {
        if (can[i] == 'N')
        {
            cases[i] = -1;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        int n;
        cin >> n;
        c[n]++;
    }

    for (int i = 0; i < 6; i++)
    {
        if (cases[i] != -1)
        {
            cases[i] = c[i + 1] * (i + 1) + 2 * (i + 1);
        }
    }

    int *f = find(c + 1, c + 7, 2);

    if (f != c + 7)
    {
        if (cases[6] != -1)
            cases[6] = (f - c) * 4;
    }

    if (f != c + 7 && cases[7] != -1)
    {
        int *full_b = find(c + 1, c + 7, 1);
        if (full_b > f)
        {
            cases[7] = (full_b - c) * 3 + (f - c) * 2;
        }
        else
        {
            cases[7] = (f - c) * 3 + (full_b - c) * 2;
        }
    }

    int *y = find(c + 1, c + 7, 3);
    if (y != c + 7 && cases[7] != -1)
    {
        if (y != c + 6)
        {
            cases[7] = (y - c) * 3 + 12;
        }
        else
        {
            cases[7] = 28;
        }
    }

    if (cases[8] != -1 && c[6] == 0 && *max_element(c + 1, c + 7) == 1)
    {
        cases[8] = 30;
    }

    if (cases[9] != -1 && c[1] == 0 && *max_element(c + 1, c + 7) == 1)
    {
        cases[9] = 30;
    }

    if (cases[10] != -1 && y != c + 7)
    {
        cases[10] = 50;
    }

    if (cases[11] != -1)
    {
        for (int i = 1; i < 7; i++)
        {
            cases[11] += c[i] * i;
        }
        cases[11] += 12;
    }

    cout << *max_element(cases, cases + 12) << endl;

    return 0;
}