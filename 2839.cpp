#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int min = 3000;
    for (int i = 0; i * 5 <= n; i++)
    {
        for (int j = 0; j * 3 <= n - i * 5; j++)
        {
            if ((n - i * 5) % 3 != 0)
                break;
            if (i * 5 + j * 3 == n && min > i + j)
                min = i + j;
        }
    }

    if (min == 3000){
        min = -1;
    }

    cout << min << endl;
}