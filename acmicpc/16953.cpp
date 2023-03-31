#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue<pair<long, long>> dp;
    long a, b;
    cin >> a >> b;
    dp.push(make_pair(1, a));
    while (!dp.empty())
    {
        pair<long, long> cur = dp.front();
        dp.pop();

        if (cur.second * 10 + 1 == b)
        {
            dp.push(make_pair(cur.first + 1, cur.second * 10 + 1));
            break;
        }
        else if (cur.second * 2 == b)
        {
            dp.push(make_pair(cur.first + 1, cur.second * 2));
            break;
        }
        if (cur.second * 10 + 1 < b)
        {
            dp.push(make_pair(cur.first + 1, cur.second * 10 + 1));
        }
        if (cur.second * 2 < b)
        {
            dp.push(make_pair(cur.first + 1, cur.second * 2));
        }
    }
    if (dp.back().second == b)
        cout << dp.back().first;
    else
        cout << -1;
    return 0;
}