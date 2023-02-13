#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int ctn = 1;
    int circle = 6;
    int a = 2;
    while (n >= a)
    {
        ctn++;
        a += circle;
        circle = 6 * ctn;
    }
    cout << ctn;
    return 0;
}