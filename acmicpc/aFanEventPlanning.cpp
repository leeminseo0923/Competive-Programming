#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    long long sumToken[n];
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        if (i == 0)
        {
            sumToken[i] = cur;
        }
        else
        {
            sumToken[i] = cur + sumToken[i - 1];
        }
    }

    vector<int> resetDay;

    while (q--)
    {
        int command;
        cin >> command;
        if (command == 1)
        {
            int d;
            cin >> d;
            resetDay.push_back(d);

            sort(resetDay.begin(), resetDay.end());
        }
        else
        {
            int s, e;
            cin >> s >> e;

            long long sum = 0;

            int startDay = s - 1;

            int front, end;
            front = 0;
            end = resetDay.size();

            while (front < end)
            {
                int mid = (front + end) / 2;

                if (resetDay[mid] > startDay && resetDay[mid] < e)
                {
                    startDay = resetDay[mid];
                    front = mid + 1;
                }
                else if (resetDay[mid] < startDay)
                {
                    front = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }

            if (startDay == 0)
            {
                sum = sumToken[e - 1];
            }
            else
            {
                sum = sumToken[e - 1] - sumToken[startDay - 1];
            }
            cout << sum << '\n';
        }
    }

    return 0;
}