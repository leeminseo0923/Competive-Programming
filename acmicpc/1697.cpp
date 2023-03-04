#include <iostream>

using namespace std;

int coord[101010];
int queue[101010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    if (n == k)
    {
        cout << 0;
        return 0;
    }

    int front, end;
    front = 0;
    end = 1;

    queue[front] = n;

    while (front < end)
    {
        if (queue[front] < 101000 && coord[queue[front] + 1] == 0)
        {
            queue[end] = queue[front] + 1;
            coord[queue[front] + 1] = coord[queue[front]] + 1;
            if (queue[end] == k)
                break;
            end++;
        }
        if (queue[front] > 0 && coord[queue[front] - 1] == 0)
        {
            queue[end] = queue[front] - 1;
            coord[queue[front] - 1] = coord[queue[front]] + 1;
            if (queue[end] == k)
                break;
            end++;
        }
        if (queue[front] * 2 < 101000 && coord[queue[front] * 2] == 0)
        {
            queue[end] = queue[front] * 2;
            coord[queue[front] * 2] = coord[queue[front]] + 1;
            if (queue[end] == k)
                break;
            end++;
        }
        front += 1;
    }

    cout << coord[k];

    return 0;
}