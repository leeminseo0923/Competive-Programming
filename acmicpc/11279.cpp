#include <iostream>
#include <algorithm>

using namespace std;

long maxHeap[101010];

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
            maxHeap[tail] = x;
            int t = tail;
            tail++;
            while (t > 1)
            {
                if (maxHeap[t] > maxHeap[t / 2])
                {
                    long temp = maxHeap[t];
                    maxHeap[t] = maxHeap[t / 2];
                    maxHeap[t / 2] = temp;
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
            cout << maxHeap[1] << "\n";
            maxHeap[1] = maxHeap[tail - 1];
            maxHeap[tail - 1] = 0;
            if (tail > 1)
                tail--;
            int t = 1;
            while (2 * t + 1 < tail)
            {
                if (maxHeap[t * 2] < maxHeap[t * 2 + 1] && maxHeap[t * 2 + 1] > maxHeap[t])
                {
                    long temp = maxHeap[t];
                    maxHeap[t] = maxHeap[t * 2 + 1];
                    maxHeap[t * 2 + 1] = temp;
                    t = t * 2 + 1;
                }
                else if (maxHeap[t * 2] > maxHeap[t * 2 + 1] && maxHeap[t * 2] > maxHeap[t])
                {
                    long temp = maxHeap[t];
                    maxHeap[t] = maxHeap[t * 2];
                    maxHeap[t * 2] = temp;
                    t *= 2;
                }
                else if (maxHeap[t * 2 + 1] > maxHeap[t])
                {
                    long temp = maxHeap[t];
                    maxHeap[t] = maxHeap[t * 2 + 1];
                    maxHeap[t * 2 + 1] = temp;
                    t = t * 2 + 1;
                }
                else
                {
                    break;
                }
            }

            if (2 * t < tail && maxHeap[t * 2] > maxHeap[t])
            {
                long temp = maxHeap[t];
                maxHeap[t] = maxHeap[t * 2];
                maxHeap[t * 2] = temp;
            }
        }
    }

    return 0;
}