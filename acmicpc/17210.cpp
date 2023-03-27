#include <iostream>

using namespace std;

string d;

int main()
{
    int n;
    cin >> n;

    int f;
    cin >> f;

    d = " " + to_string(f);

    for (int i = 2; i <= n; i++)
    {
        if (d[i - 1] == '0')
        {
            d.push_back('1');
        }
        else
        {
            d.push_back('0');
        }

        if (i % 2 == 0 && i > 2 && d[i / 2] != d[i])
        {
            cout << "Love is open door";
            return 0;
        }
        if (i % 3 == 0 && i > 3 && d[i / 3] != d[i])
        {
            cout << "Love is open door";
            return 0;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        cout << d[i] << endl;
    }

    return 0;
}