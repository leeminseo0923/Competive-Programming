#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> p;

    for (int i = 0; i < n; i++)
    {
        int p_;
        cin >> p_;
        p.push_back(p_);
    }

    long long k;
    cin >> k;

    long long res = 0;

    for (long long i = 1; i <= k; i++)
    {
        int x = 2;
        int y = 2;

        int divisor = i;

        while (divisor > 1)
        {
        }
    }

    cout << res;

    return 0;
}