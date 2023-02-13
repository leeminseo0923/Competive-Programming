#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    long long A[n];

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cin >> m;

    sort(A, A + n);

    for (int i = 0; i < m; i++)
    {
        int start = 0;
        int end = n - 1;
        int mid;

        long long num;
        cin >> num;

        while (start < end)
        {
            mid = (start + end) / 2;

            if (A[mid] < num)
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        if (A[start] == num)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}