#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    cin >> n;

    int res = 0;
    int ctn2 = 0;
    int ctn5 = 0;

    while (n > 1)
    {
        int i = n;
        while (i % 10 == 0)
        {
            i /= 10;
            res++;
        }
        while (i % 2 == 0)
        {
            ctn2++;
            i /= 2;
        }
        while (i % 5 == 0)
        {
            ctn5++;
            i /= 5;
        }
        n--;
    }

    res += min(ctn2, ctn5);

    cout << res;

    return 0;
}