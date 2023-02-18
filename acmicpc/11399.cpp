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

    int time[n];

    for (int i = 0; i < n; i++)
    {
        cin >> time[i];
    }

    sort(time, time + n);

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        result += time[i] * (n - i);
    }

    cout << result;

    return 0;
}