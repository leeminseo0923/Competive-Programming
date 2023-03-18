#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    while (n--)
    {
        int b;
        cin >> b;
        a.push_back(b);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}