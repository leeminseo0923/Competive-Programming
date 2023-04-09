#include <bits/stdc++.h>

using namespace std;

int table[101010][3];
int dpMax[3];
int dpMin[3];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> table[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        dpMax[i] = dpMin[i] = table[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        int nextMax[3];
        int nextMin[3];

        nextMax[0] = *max_element(dpMax, dpMax + 2) + table[i][0];
        nextMin[0] = *min_element(dpMin, dpMin + 2) + table[i][0];

        nextMax[1] = *max_element(dpMax, dpMax + 3) + table[i][1];
        nextMin[1] = *min_element(dpMin, dpMin + 3) + table[i][1];

        nextMax[2] = *max_element(dpMax + 1, dpMax + 3) + table[i][2];
        nextMin[2] = *min_element(dpMin + 1, dpMin + 3) + table[i][2];

        for (int j = 0; j < 3; j++)
        {
            dpMax[j] = nextMax[j];
            dpMin[j] = nextMin[j];
        }
    }

    cout << *max_element(dpMax, dpMax + 3) << ' ' << *min_element(dpMin, dpMin + 3);

    return 0;
}