#include <bits/stdc++.h>

using namespace std;

int arr[81];

int main()
{
    for (int i = 0; i < 81; i++)
    {
        cin >> arr[i];
    }

    int *m = max_element(arr, arr + 81);

    cout << *m << '\n'
         << (m - arr) / 9 + 1 << ' ' << (m - arr) % 9 + 1;

    return 0;
}