#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    deque<int> q;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        while (!q.empty())
            q.pop_front();
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            q.push_back(num);
        }
        int ctn = 0;
        while (!q.empty())
        {
            for (int i = 1; i < n; i++)
            {
                if (q.front() < q[i])
                {
                    q.push_back(q.front());
                    q.pop_front();
                    if (m > 0)
                        m--;
                    else
                        m = q.size() - 1;
                    i = 0;
                }
            }
            q.pop_front();
            ctn++;
            if (m > 0)
            {
                m--;
                n--;
            }
            else
            {
                cout << ctn << '\n';
                break;
            }
        }
    }
    return 0;
}
