#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    while (n + m > 0)
    {
        if (n % m == 0)
        {
            cout << "multiple" << '\n';
        }
        else if (m % n == 0)
        {
            cout << "factor" << '\n';
        }
        else
        {
            cout << "neither" << '\n';
        }
        cin >> n >> m;
    }
    return 0;
}