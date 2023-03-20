#include <iostream>
#include <vector>

using namespace std;

int atoz[26];

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        atoz[s[i] - 'A']++;
    }

    vector<char> even;
    char odd = '\0';

    for (int i = 0; i < 26; i++)
    {
        if (atoz[i] > 0)
        {
            if (atoz[i] % 2 == 0)
            {
                for (int j = 0; j < atoz[i] / 2; j++)
                {
                    even.push_back(i + 'A');
                }
            }
            else if (odd == '\0')
            {
                odd = i + 'A';
                for (int j = 0; j < atoz[i] / 2; j++)
                {
                    even.push_back(i + 'A');
                }
            }
            else
            {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }
    }

    for (int i = 0; i < even.size(); i++)
    {
        cout << even[i];
    }
    if (odd != '\0')
        cout << odd;
    for (int i = even.size() - 1; i >= 0; i--)
    {
        cout << even[i];
    }
    return 0;
}