#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int points[300];

    int maxSum[300];

    int series = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> points[i];
    }

    maxSum[0] = points[0];
    maxSum[1] = points[1] + maxSum[0];

    for (int i = 2; i < n; i++)
    {
        if (i >= 3)
            maxSum[i] = max(maxSum[i - 2] + points[i], maxSum[i - 3] + points[i - 1] + points[i]);
        else
            maxSum[i] = max(maxSum[i - 2] + points[i], points[i - 1] + points[i]);
    }

    cout << maxSum[n - 1];

    return 0;
}