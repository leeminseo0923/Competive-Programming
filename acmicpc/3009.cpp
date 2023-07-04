#include <iostream>

using namespace std;
int arrx[1001];
int arry[1001];

int main()
{
    for (int i = 0; i < 3; i++)
    {
        int x, y;
        cin >> x >> y;
        arrx[x]++;
        arry[y]++;
    }

    for (int i = 0; i < 1001; i++)
    {
        if (arrx[i] == 1)
            cout << i << ' ';
    }
    for (int i = 0; i < 1001; i++)
    {
        if (arry[i] == 1)
            cout << i;
    }

    return 0;
}