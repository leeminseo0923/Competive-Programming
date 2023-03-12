#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;

    vector<int> a;

    for (int i = 0; i < n; i++)
    {
        int a_i;
        cin >> a_i;
        a.push_back(a_i);
    }

    string command;
    cin >> command;

    for (int i = command.size() - 1; i >= 0; i--)
    {
        cout << command[i];
    }

    return 0;
}