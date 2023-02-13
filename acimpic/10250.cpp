#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h, w, n;

        cin >> h >> w >> n;

        int ho = ceil((double)n / (double)h);
        int stair = n % h == 0 ? h : n % h;

        cout << stair * 100 + ho << endl;
    }
}