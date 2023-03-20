#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        cout << (char)((s[i] - 3) >= 'A' ? s[i] - 3 : (s[i] + 23));
    }
    return 0;
}