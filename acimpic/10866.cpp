#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int deque[20202];

    int start, end;
    start = end = 10101;

    while (n--)
    {
        string command;
        cin >> command;
        if (command == "push_front")
        {
            int num;
            cin >> num;
            start--;
            deque[start] = num;
        }
        else if (command == "push_back")
        {
            int num;
            cin >> num;
            deque[end] = num;
            end++;
        }
        else if (command == "pop_front")
        {
            if (end - start > 0)
            {
                cout << deque[start] << endl;
                start++;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (command == "pop_back")
        {
            if (end - start > 0)
            {
                cout << deque[end - 1] << endl;
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
            if (end - start > 0)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }
        else if (command == "front")
        {
            if (end - start > 0)
            {
                cout << deque[start] << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {
            if (end - start > 0)
            {
                cout << deque[end - 1] << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}