#include <iostream>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    pair<int, int> coord[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coord[i].first >> coord[i].second;
    }
    sort(coord, coord + n, comp);

    for (int i = 0; i < n; i++)
    {
        cout << coord[i].first << ' ' << coord[i].second << '\n';
    }
    return 0;
}