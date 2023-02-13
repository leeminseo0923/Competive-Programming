#include <iostream>

using namespace std;

long long n, m;

long long cut_trees(long long trees[], long long length)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (trees[i] > length)
            sum += trees[i] - length;
    }
    return sum;
}

long long binary_search(long long trees[], long long start, long long end, long long target)
{
    long long max = 0;

    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long length = cut_trees(trees, mid);

        if (length >= target)
        {
            if (max < mid)
            {
                max = mid;
            }
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    long long end = 0;

    long long trees[n];

    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
        if (trees[i] > end)
        {
            end = trees[i];
        }
    }

    cout << binary_search(trees, 0, end, m);

    return 0;
}