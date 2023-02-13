#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    char output[2 * n];
    int last = 1;
    int idx = 0;

    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (s.empty() || s.top() != num)
        {
            for (int j = last; j <= num; j++)
            {
                output[idx] = '+';
                idx++;
                s.push(j);
                last = j;
            }
            last++;
        }
        if (s.top() == num)
        {
            output[idx] = '-';
            idx++;
            s.pop();
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    for (int i = 0; i < 2 * n; i++)
    {
        cout << output[i];
        if (i + 1 < 2 * n)
        {
            cout << '\n';
        }
    }
    return 0;
}