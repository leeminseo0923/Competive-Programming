#include <bits/stdc++.h>

using namespace std;

int atoz[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        atoz[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << atoz[i] << ' ';
    }

    return 0;
}