#include <iostream>
#include <algorithm>

using namespace std;

bool comp(string a, string b)
{
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }
    int val = a.compare(b);
    if (val >= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int N;
    cin >> N;

    string list[N + 1];
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
    }
    sort(list, list + N, comp);

    string s = list[0];
    int i = 0;
    while (s != "")
    {
        cout << s << endl;
        i++;
        while (list[i] == list[i - 1])
        {
            i++;
        }

        s = list[i];
    }

    return 0;
}