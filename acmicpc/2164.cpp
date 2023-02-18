#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int card[1010101];

    int start = 0;
    int end = n - 1;
    for (int i = 0; i < n; i++)
    {
        card[i] = i + 1;
    }

    while (start < end)
    {
        start++;
        card[end + 1] = card[start];
        end++;
        start++;
    }

    cout << card[start];

    return 0;
}