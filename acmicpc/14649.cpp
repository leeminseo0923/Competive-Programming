#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed;
    cout.precision(2);

    double p;
    cin >> p;

    int n;
    cin >> n;

    int bridge[101] = {
        0,
    };

    while (n--)
    {
        int cur;
        char dir;
        cin >> cur >> dir;

        if (dir == 'L')
        {
            for (int i = cur - 1; i >= 1; i--)
            {
                bridge[i]++;
            }
        }
        else
        {
            for (int i = cur + 1; i <= 100; i++)
            {
                bridge[i]++;
            }
        }
    }

    double red, blue, green;

    for (int i = 1; i < 101; i++)
    {
        switch (bridge[i] % 3)
        {
        case 0:
            blue++;
            break;
        case 1:
            red++;
            break;
        case 2:
            green++;
            break;
        default:
            break;
        }
    }

    printf("%.2f %.2f %.2f", p * blue / (red + green + blue), p * red / (red + green + blue), p * green / (red + green + blue));

    return 0;
}