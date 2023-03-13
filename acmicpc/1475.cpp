#include <bits/stdc++.h>

using namespace std;

int num[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string n;
    cin >> n;

    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] == '6' || n[i] == '9')
        {
            if (num[6] > num[9])
            {
                num[9]++;
            }
            else
            {
                num[6]++;
            }
        }
        else
        {
            num[n[i] - '0']++;
        }
    }

    cout << *max_element(num, num + 10);

    return 0;
}