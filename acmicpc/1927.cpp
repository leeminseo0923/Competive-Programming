#include <iostream>
#include <algorithm>

using namespace std;

long minHeap[101010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int tail = 1;
    while (n--)
    {
        long x;
        cin >> x;
        if (x > 0)
        {
            minHeap[tail] = x;
            int t = tail;
            tail++;
            while (t > 1)
            {
                if (minHeap[t] < minHeap[t / 2])
                {
                    long temp = minHeap[t];
                    minHeap[t] = minHeap[t / 2];
                    minHeap[t / 2] = temp;
                    t /= 2;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            cout << minHeap[1] << "\n";
            minHeap[1] = minHeap[tail - 1];
            minHeap[tail - 1] = 0;
            if (tail > 1)
                tail--;
            int t = 1;
            while (2 * t + 1 < tail)
            {
                if (minHeap[t * 2] > minHeap[t * 2 + 1] && minHeap[t * 2 + 1] < minHeap[t])
                {
                    long temp = minHeap[t];
                    minHeap[t] = minHeap[t * 2 + 1];
                    minHeap[t * 2 + 1] = temp;
                    t = t * 2 + 1;
                }
                else if (minHeap[t * 2] < minHeap[t * 2 + 1] && minHeap[t * 2] < minHeap[t])
                {
                    long temp = minHeap[t];
                    minHeap[t] = minHeap[t * 2];
                    minHeap[t * 2] = temp;
                    t *= 2;
                }
                else
                {
                    break;
                }
            }
            if (2 * t < tail && minHeap[t * 2] < minHeap[t])
            {
                long temp = minHeap[t];
                minHeap[t] = minHeap[t * 2];
                minHeap[t * 2] = temp;
            }
        }
    }

    return 0;
}