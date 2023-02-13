#include <iostream>

using namespace std;

void merge(pair<int, string> d[], int start, int end)
{
    int mid = (start + end) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    pair<int, string> leftArr[len1], rightArr[len2];

    for (int i = 0; i < len1; i++)
    {
        leftArr[i] = d[start + i];
    }
    for (int i = 0; i < len2; i++)
    {
        rightArr[i] = d[mid + 1 + i];
    }
    int i, j, k;
    i = j = 0;
    k = start;

    while (i < len1 and j < len2)
    {
        if (leftArr[i].first <= rightArr[j].first)
        {
            d[k] = leftArr[i];
            i++;
        }
        else
        {
            d[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < len1)
    {
        d[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < len2)
    {
        d[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(pair<int, string> d[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(d, start, mid);
        mergeSort(d, mid + 1, end);

        merge(d, start, end);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    pair<int, string> d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i].first >> d[i].second;
    }

    mergeSort(d, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << d[i].first << " " << d[i].second << "\n";
    }
}