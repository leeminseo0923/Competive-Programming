#include <iostream>
#include <algorithm>

using namespace std;

int biSearch(int *arr, int start, int end, int target)
{
    int mid = (start + end) / 2;
    if (arr[mid] == target || start > end)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return biSearch(arr, start, mid, target);
    }
    else
    {
        return biSearch(arr, mid + 1, end, target);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int order[n];
    int numbers[n];
    int sorted[n];
    int ctn = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        sorted[i] = numbers[i];
    }

    sort(sorted, sorted + n);

    for (int i = 0; i < n;)
    {
        order[ctn] = sorted[i];
        while (i < n && order[ctn] == sorted[i])
            i++;
        ctn++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << biSearch(order, 0, ctn, numbers[i]) << " ";
    }

    return 0;
}