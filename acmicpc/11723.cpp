#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s[20] = {
        0,
    };

    int m;
    cin >> m;

    while (m--)
    {
        string command;
        cin >> command;

        if (command == "all" or command == "empty")
        {
            for (int i = 0; i < 20; i++)
            {
                if (command == "all")
                    s[i] = 1;
                else
                    s[i] = 0;
            }
        }
        else
        {
            int x;
            cin >> x;

            if (command == "add")
                s[x - 1] = 1;
            if (command == "remove")
                s[x - 1] = 0;
            if (command == "check")
                cout << s[x - 1] << '\n';
            if (command == "toggle")
                s[x - 1] = !s[x - 1];
        }
    }

    return 0;
}