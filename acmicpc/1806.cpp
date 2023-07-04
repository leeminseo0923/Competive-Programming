#include <iostream>

using namespace std;

int cumalative_sum[202020];

int main()
{
    int n, s;
    cin >> n >> s;

    for (int i = 1; i <= n; i++)
    {
        int item;
        cin >> item;
        cumalative_sum[i] = item + cumalative_sum[i - 1];
    }

    if (cumalative_sum[n] < s)
    {
        cout << 0;
        return 0;
    }

    int min_length = n;
    while (cumalative_sum[min_length] >= s)
        min_length--;
    min_length++;

    for (int i = 1; i <= n; i++)
    {
        int rear = min(min_length + i, n);
        if (cumalative_sum[rear] - cumalative_sum[i] >= s)
        {
            min_length = rear - i;
            while (cumalative_sum[rear] - cumalative_sum[i] >= s)
            {
                min_length--;
                rear = min(min_length + i, n);
            }
            min_length++;
        }
    }

    cout << min_length;

    return 0;
}