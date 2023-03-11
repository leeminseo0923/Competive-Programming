#include <iostream>
#include <utility>

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
        int n;
        cin >> n;

        string meow;
        cin >> meow;
        pair<int, int> prove[4] = {make_pair('m', 'M'), make_pair('e', 'E'), make_pair('o', 'O'), make_pair('w', 'W')};

        int cur = 0;

        int error = 0;

        for (int i = 0; i < 4; i++)
        {
            int ctn = 0;
            while (cur + ctn < meow.size())
            {
                if (prove[i].first == meow[cur + ctn] || prove[i].second == meow[cur + ctn])
                {
                    ctn++;
                }
                else
                {
                    break;
                }
            }
            cur += ctn;
            if (ctn == 0)
            {
                error = 1;
                break;
            }
        }

        if (cur < meow.size() || error)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
        }
    }

    return 0;
}