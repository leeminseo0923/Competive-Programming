#include <iostream>

using namespace std;

bool paper[100][100];

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        for (int i = x; i < x + 10; i++)
        {
            for (int j = y; j < y + 10; j++)
            {
                paper[i][j] = true;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (paper[i][j])
                result++;
        }
    }
    cout << result;
    return 0;
}