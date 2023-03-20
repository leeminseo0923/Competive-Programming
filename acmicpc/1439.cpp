#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int ctn[2] = {
        0,
    };

    char cur = s[0];
    ctn[s[0] - '0']++;

    for (int i = 1; i < s.size(); i++)
    {
        if (cur != s[i])
        {
            ctn[s[i] - '0']++;
            cur = s[i];
        }
    }

    cout << min(ctn[0], ctn[1]);

    return 0;
}