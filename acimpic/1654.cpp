#include <iostream>

using namespace std;

int main()
{
    long long start = 1;
    long long end = 1;
    end <<= 31;
    end--;

    long long k, n;
    cin >> k >> n;

    long long lan[k];

    for (int i = 0; i < k; i++)
    {
        cin >> lan[i];
    }

    long long maxLan = 0;

    while (start <= end)
    {
        long long count = 0;
        long long mid = (start + end) / 2;

        for (int i = 0; i < k; i++)
        {
            count += lan[i] / mid;
        }
        if (count >= n)
        {
            maxLan = max(maxLan, mid);
            start = mid + 1;
        }
        else
        {
            end = mid;
            if (start == mid)
                break;
        }
    }
    cout << maxLan;

    return 0;
}