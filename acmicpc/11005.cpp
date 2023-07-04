#include <iostream>

using namespace std;

int result[20];
int main()
{
    int n, b;
    cin >> n >> b;

    int cnt = 0;

    while (n > 0)
    {
        result[cnt] = n % b;
        cnt++;
        n /= b;
    }

    for (int i = cnt - 1; i >= 0; i--)
    {
        if (result[i] >= 0 && result[i] <= 9)
            cout << result[i];
        else
            cout << (char)(result[i] - 10 + 'A');
    }

    return 0;
}