#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, b;
    cin >> n >> m >> b;

    int house[n][m];
    int min = 257;
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> house[i][j];
            if (house[i][j] > max)
                max = house[i][j];
            if (house[i][j] < min)
                min = house[i][j];
        }
    }
    long long minTime = -1;
    long long result = 0;
    for (int floor = min; floor <= max; floor++)
    {
        long long sumTime = 0;
        long long getBlock = b;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (floor < house[i][j])
                {
                    sumTime += 2 * (house[i][j] - floor);
                    getBlock += house[i][j] - floor;
                }
                else if (floor > house[i][j])
                {
                    sumTime += floor - house[i][j];
                    getBlock -= floor - house[i][j];
                }
            }
        }
        if (minTime < 0 || (sumTime <= minTime && getBlock >= 0))
        {
            minTime = sumTime;
            result = floor;
        }
    }

    cout << minTime << ' ' << result;

    return 0;
}