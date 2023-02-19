#include <iostream>
#include <algorithm>

using namespace std;

int number[1010101] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    number[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        number[i] = number[i - 1] + 1;
        if (i % 2 == 0)
        {
            number[i] = min(number[i], number[i / 2] + 1);
        }
        if (i % 3 == 0)
        {
            number[i] = min(number[i], number[i / 3] + 1);
        }
    }

    cout << number[n];

    return 0;
}