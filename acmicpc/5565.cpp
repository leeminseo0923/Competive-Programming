#include <iostream>

using namespace std;

int main()
{
    int sum;
    cin >> sum;

    for (int i = 0; i < 9; i++)
    {
        int book;
        cin >> book;
        sum -= book;
    }
    cout << sum;
}