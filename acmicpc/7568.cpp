#include <iostream>

using namespace std;

pair<int, int> people[50];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> people[i].first >> people[i].second;
    }

    for (int i = 0; i < n; i++)
    {
        int ctn = 1;
        for (int j = 0; j < n; j++)
        {
            if (people[j].first > people[i].first && people[j].second > people[i].second)
                ctn++;
        }
        cout << ctn << '\n';
    }

    return 0;
}