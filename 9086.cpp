#include <iostream>

using namespace std;

int main()
{
    int a = 0;

    for (int i = 0; i < 5; i++)
    {
        int t;
        cin >> t;
        a += t * t;
    }

    cout << a % 10;
}