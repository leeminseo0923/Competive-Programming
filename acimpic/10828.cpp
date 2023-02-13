#include <iostream>
using namespace std;

int main()
{
    int n;
    int d[10101];
    int start = 0;
    int end = 0;
    cin >> n;
    while (n--)
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
                cout << d[end - 1] << endl;
                end--;
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
            if (end - start == 0)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else
        {
            if (end - start > 0)
            {
                cout << d[end - 1] << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}