#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int right[] = {1, 1, 2, 2, 2, 8};

    for (int i = 0; i < 6; i++)
    {
        int a;
        cin >> a;

        cout << right[i] - a << ' ';
    }

    return 0;
}