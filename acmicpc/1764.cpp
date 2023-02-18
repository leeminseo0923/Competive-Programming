#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string notHearSee[500000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string notHear[n];
    string notSee[m];

    for (int i = 0; i < n; i++)
    {
        cin >> notHear[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> notSee[i];
    }

    sort(notHear, notHear + n);
    sort(notSee, notSee + m);

    int ctn = 0;

    for (int i = 0; i < n; i++)
    {
        if (binary_search(notSee, notSee + m, notHear[i]))
        {
            notHearSee[ctn] = notHear[i];
            ctn++;
        }
    }

    cout << ctn << "\n";

    for (int i = 0; i < ctn; i++)
    {
        cout << notHearSee[i] << "\n";
    }

    return 0;
}