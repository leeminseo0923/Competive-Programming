#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int arr[n];
    int sum[100000] = {
        0,
    };
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        sum[i + 1] = sum[i] + num;
    }

    while (m--)
    {
        int front, back;

        cin >> front >> back;

        cout << sum[back] - sum[front - 1] << "\n";
    }
    return 0;
}