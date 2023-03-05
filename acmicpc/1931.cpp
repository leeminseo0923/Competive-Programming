#include <iostream>
#include <vector>
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

    vector<pair<long, long>> t;

    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;

        t.push_back(make_pair(e, s));
    }

    sort(t.begin(), t.end());

    int end = 0;
    int ctn = 0;

    for (int i = 0; i < n; i++)
    {
        if (t[i].second >= end)
        {
            end = t[i].first;
            ctn++;
        }
    }

    cout << ctn;
    return 0;
}