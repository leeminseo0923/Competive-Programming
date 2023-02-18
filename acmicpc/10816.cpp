#include <iostream>
using namespace std;
int san[20202020];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        int s;
        cin >> s;
        san[s + 10000000]++;
    }
    int m;
    cin >> m;
    while (m--)
    {
        int f;
        cin >> f;
        cout << san[f + 10000000];
        if (m > 0)
        {
            cout << " ";
        }
    }
    return 0;
}