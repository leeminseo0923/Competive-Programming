#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        v.push_back(cur);
    }

    sort(v.begin(), v.end());

    int clear = (n * 15 + 50) / 100;
    double sum = 0;

    for (int i = clear; i < n - clear; i++)
    {
        sum += v[i];
    }

    cout << (int)round(sum / (n - clear * 2));

    return 0;
}