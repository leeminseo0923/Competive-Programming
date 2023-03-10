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

    while (t--)
    {
        string p;
        cin >> p;

        int n;
        cin >> n;

        deque<int> xArr;

        int flag = 0;

        int error = 0;

        string input;
        cin >> input;
        string tmp = "";

        if (n != 0)
        {
            for (int j = 0; j < input.length(); j++)
            {
                if (input[j] == '[' || input[j] == ']' || input[j] == ',')
                {
                    if (input[j] != '[')
                        xArr.push_back(stoi(tmp));
                    tmp = "";
                    continue;
                }
                tmp += input[j];
            }
        }

        for (int i = 0; i < p.size(); i++)
        {
            char cur = p[i];

            if (cur == 'R')
            {
                if (flag)
                {
                    flag = false;
                }
                else
                {
                    flag = true;
                }
            }
            else
            {
                if (!xArr.empty())
                {
                    if (flag)
                    {
                        xArr.pop_back();
                    }
                    else
                    {
                        xArr.pop_front();
                    }
                }
                else
                {
                    error = 1;
                    break;
                }
            }
        }

        if (!error)
        {
            cout << '[';
            if (flag == 1)
            {
                while (!xArr.empty())
                {
                    if (xArr.size() > 1)
                    {
                        cout << xArr.back() << ',';
                    }
                    else
                    {
                        cout << xArr.back();
                    }
                    xArr.pop_back();
                }
            }
            else
            {
                while (!xArr.empty())
                {
                    if (xArr.size() > 1)
                    {
                        cout << xArr.front() << ',';
                    }
                    else
                    {
                        cout << xArr.front();
                    }
                    xArr.pop_front();
                }
            }
            cout << ']' << '\n';
        }
        else
        {
            cout << "error" << '\n';
        }
    }

    return 0;
}