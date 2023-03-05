#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int queue[1010101];

void swap(int idx1, int idx2)
{
    int temp = queue[idx1];
    queue[idx1] = queue[idx2];
    queue[idx2] = temp;
}

void pushDown(int cur, int level, int end)
{
    while (cur <= end / 2)
    {
        int i = cur;
        if (level % 2 == 0)
        {
            cur = i * 2;
            int m = queue[i * 2];
            if (i * 2 + 1 <= end && m > queue[i * 2 + 1])
            {
                cur = i * 2 + 1;
                m = queue[i * 2 + 1];
            }
            for (int j = 0; j < 4; j++)
            {
                if (i * 4 + j <= end && m > queue[i * 4 + j])
                {
                    cur = i * 4 + j;
                    m = queue[i * 4 + j];
                }
            }
            if (queue[cur] < queue[i])
            {
                swap(cur, i);
                if (cur / 4 == i)
                {
                    if (queue[cur] > queue[cur / 2])
                    {
                        swap(cur, cur / 2);
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        else
        {
            cur = i * 2;
            int m = queue[i * 2];
            if (i * 2 + 1 <= end && m < queue[i * 2 + 1])
            {
                cur = i * 2 + 1;
                m = queue[i * 2 + 1];
            }
            for (int j = 0; j < 4; j++)
            {
                if (i * 4 + j <= end && m < queue[i * 4 + j])
                {
                    cur = i * 4 + j;
                    m = queue[i * 4 + j];
                }
            }
            if (queue[cur] > queue[i])
            {
                swap(cur, i);
                if (cur / 4 == i)
                {
                    if (queue[cur] < queue[cur / 2])
                    {
                        swap(cur, cur / 2);
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
}

void pushUpMin(int cur)
{
    while (cur / 2 > 1)
    {
        if (queue[cur / 4] > queue[cur])
        {
            swap(cur, cur / 4);
        }
        else
        {
            break;
        }
        cur /= 4;
    }
}

void pushUpMax(int cur)
{
    while (cur / 2 > 1)
    {
        if (queue[cur / 4] < queue[cur])
        {
            swap(cur, cur / 4);
        }
        else
        {
            break;
        }
        cur /= 4;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;

        int ctn = 0;

        while (k--)
        {
            char command;
            int num;
            cin >> command >> num;
            if (command == 'I')
            {
                ctn++;
                queue[ctn] = num;

                if (ctn > 1)
                {
                    int level = (int)log2((float)(ctn));

                    if (level % 2)
                    {
                        if (queue[ctn] < queue[ctn / 2])
                        {
                            swap(ctn, ctn / 2);
                            pushUpMin(ctn / 2);
                        }
                        else
                        {
                            pushUpMax(ctn);
                        }
                    }
                    else
                    {
                        if (queue[ctn] > queue[ctn / 2])
                        {
                            swap(ctn, ctn / 2);
                            pushUpMax(ctn / 2);
                        }
                        else
                        {
                            pushUpMin(ctn);
                        }
                    }
                }
            }
            else
            {
                if (num == -1)
                {
                    if (ctn > 1)
                    {
                        queue[1] = queue[ctn];
                        queue[ctn] = 0;
                        ctn--;
                        pushDown(1, 0, ctn);
                    }
                    else if (ctn > 0)
                    {
                        queue[ctn] = 0;
                        ctn--;
                    }
                }
                else if (num == 1)
                {
                    if (ctn > 2)
                    {
                        if (queue[3] > queue[2])
                        {
                            queue[3] = queue[ctn];
                            queue[ctn] = 0;
                            ctn--;
                            pushDown(3, 1, ctn);
                        }
                        else
                        {
                            queue[2] = queue[ctn];
                            queue[ctn] = 0;
                            ctn--;
                            pushDown(2, 1, ctn);
                        }
                    }
                    else if (ctn > 0)
                    {
                        queue[ctn] = 0;
                        ctn--;
                    }
                }
            }
        }

        if (ctn == 0)
        {
            cout << "EMPTY" << '\n';
        }
        else
        {
            if (ctn > 2)
            {
                if (queue[2] > queue[3])
                {
                    cout << queue[2] << " ";
                }
                else
                {
                    cout << queue[3] << " ";
                }
            }
            else if (ctn == 2)
            {
                cout << queue[2] << " ";
            }
            else
            {
                cout << queue[1] << " ";
            }
            cout << queue[1] << '\n';
        }
    }

    return 0;
}