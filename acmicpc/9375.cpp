#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        map<string, int> m;

        int n;
        cin >> n;
        int res = 1;

        for (int i = 1; i <= n; i++)
        {
            string clothes, clothesType;
            cin >> clothes >> clothesType;

            if (m.count(clothesType) == 0)
            {
                m[clothesType] = 1;
            }
            else
            {
                m[clothesType]++;
            }
        }
        for (auto i : m)
        {
            res *= (i.second + 1);
        }
        cout << res - 1 << '\n';
    }

    return 0;
}