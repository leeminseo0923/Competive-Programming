#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;
    while (a > 0 and b > 0 and c > 0)
    {

        int m = max(max(a, b), c);

        if (m == a)
        {
            if (m * m == b * b + c * c)
                cout << "right" << endl;
            else
                cout << "wrong" << endl;
        }
        else if (m == b)
        {
            if (m * m == a * a + c * c)
                cout << "right" << endl;
            else
                cout << "wrong" << endl;
        }
        else
        {
            if (m * m == a * a + b * b)
                cout << "right" << endl;
            else
                cout << "wrong" << endl;
        }
        cin >> a >> b >> c;
    }
    return 0;
}