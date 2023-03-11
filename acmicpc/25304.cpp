#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        n -= a * b;
    }

    if (n == 0)
    {
        cout << "Yes";
    }
    else
        cout << "No";

    return 0;
}