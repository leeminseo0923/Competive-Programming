#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    bool vps = true;
    while (t--)
    {
        string a;
        cin >> a;

        while (a.length() > 0)
        {
            size_t found = a.find("()");
            if (found != string::npos)
            {
                a.erase(found, 2);
            }
            else
            {
                vps = false;
                break;
            }
        }

        if (vps)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
        vps = true;
    }
    return 0;
}