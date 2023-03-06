#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int m;
    cin >> m;

    int err[m];
    for (int i = 0; i < m; i++)
    {
        cin >> err[i];
    }

    int minClick = abs(n - 100);

    for (int i = 0; log10(i) < 6; i++)
    {
        string makeNum = to_string(i);
        int flag = 0;
        for (int j = 0; j < m; j++)
        {
            if (makeNum.find(to_string(err[j])) != string::npos)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            minClick = min(minClick, abs(i - n) + (int)makeNum.length());
        }
    }

    cout << minClick;

    return 0;
}