#include <iostream>

using namespace std;

int main()
{
    int d[10101];

    int n;
    cin >> n;
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "push")
        {
            int num;
            cin >> num;
            d[end] = num;
            end++;
        }
        else if (command == "pop")
        {
            if (end - start > 0)
            {
                cout << d[start] << endl;
                start++;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (command == "size")
        {
            cout << end - start << endl;
        }
        else if (command == "empty")
        {
            if (end == start)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (command == "front")
        {
            if (end - start > 0)
                cout << d[start] << endl;
            else
                cout << -1 << endl;
        }
        else
        {
            if (end - start > 0)
                cout << d[end - 1] << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}