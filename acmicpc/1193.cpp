#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    int a, b;

    a = b = 1;
    x--;
    bool flag = false;
    while (x--)
    {
        if (flag)
        {
            if (b == 1)
            {
                a++;
                flag = !flag;
            }
            else
            {
                b--;
                a++;
            }
        }
        else
        {
            if (a == 1)
            {
                b++;
                flag = !flag;
            }
            else
            {
                a--;
                b++;
            }
        }
    }

    cout << a << '/' << b;
    return 0;
}