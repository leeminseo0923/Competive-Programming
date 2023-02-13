#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int num[n];
    long long max, min, sum;
    max = -4001;
    min = 4001;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        if (num[i] > max)
        {
            max = num[i];
        }
        if (num[i] < min)
        {
            min = num[i];
        }
        sum += num[i];
    }

    sort(num, num + n);
    int mode = num[0];
    int mode_max = 0;
    int mode_count = 0;

    for (int i = 0; i < n;)
    {
        int t = count(num + i, num + n, num[i]);
        if (t >= mode_max)
        {
            if (mode_max == t)
            {
                if (mode_count < 1)
                {
                    mode = num[i];
                }
                mode_count++;
            }
            else
            {
                mode = num[i];
                mode_count = 0;
                mode_max = t;
            }
        }
        i += t;
    }

    double avg = round(sum / (double)n);
    if (avg == 0)
    {
        avg = 0;
    }
    cout << avg << '\n'
         << num[n / 2] << '\n'
         << mode << '\n'
         << max - min;

    return 0;
}